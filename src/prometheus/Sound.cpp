#include "Sound.h"
#include "stb_vorbis.h"
#include <string>
#include <memory>


namespace prometheus
{
	

	void prometheus::Sound::Load(std::string path)
	{
		bufferId = 0;
		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;

		alGenBuffers(1, &bufferId);
		

		try
		{
			LoadOgg(path, bufferData, format, freq);
			alBufferData(bufferId, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);
		}
		catch (std::exception&e)
		{
			std::cout << "Problem loading audio file " << e.what() << std::endl;
		}
		

	}

	void prometheus::Sound::Play(float volume, float min, float max)
	{

	}

	void prometheus::Sound::Play()
	{

	}

	void prometheus::Sound::LoadOgg(const std::string& fileName, std::vector<char>& buffer,
		ALenum &format, ALsizei &freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;


		size_t samples = stb_vorbis_decode_filename(fileName.c_str(), &channels, &sampleRate, &output);

		

		if (samples == 0)
		{
			throw std::exception();
		}
		// Record the sample rate required by OpenAL
		try
		{
			freq = sampleRate;
		}
		catch(std::exception& e)
		{
			throw rend::Exception("Problem setting sample rate.");
		}
		

		// Record the format required by OpenAL
		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}
		else
		{
			format = AL_FORMAT_STEREO16;

			// Force format to be mono (Useful for positional audio)
			// format = AL_FORMAT_MONO16;
			// freq *= 2;
		}

		// Allocate enough space based on short (two chars) multipled by the number of
		// channels and length of clip

		try
		{
			buffer.resize(sizeof(*output) * channels * samples);
			memcpy(&buffer.at(0), output, buffer.size());
			free(output);
		}
		catch (std::exception& e)
		{
			std::cout << "Problem resizing sound buffer " << e.what() << std::endl;
		}
	}

}

