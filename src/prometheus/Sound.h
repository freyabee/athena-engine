#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <string>
#include <memory>
#include "AL/al.h"
#include "Resource.h"
namespace prometheus
{
	class SoundSource;

	/// Encapsulates the loading of sound resources and handling of sound playing.
	/// Loads ogg files to buffer and contains functions to initiate playing.
	///
	class Sound : public Resource
	{
	public:
		/// Function to load .ogg file into sound buffer. 
		/// Sets buffer id and generates buffers, loads ogg into that buffer.
		/// @param path Path of audio file in directory.
		void Load(std::string path);

		void Play(float volume, float min, float max);
		void Play();

		/// Loading of .ogg file to buffer.
		/// @param fileName Path to audio file in directory.
		/// @param buffer Pointer to buffer object to load audio into.
		/// @param format Pointer to format flag.
		/// @param freq Pointer to frequency flag.
		void LoadOgg(const std::string& fileName, std::vector<char>& buffer,
			ALenum &format, ALsizei &freq);
	private:
		friend class SoundSource;
		/// Buffer ID
		ALuint bufferId;

	};
}
#endif // !_SOUND_H_
