#include "SoundSource.h"
#include "Sound.h"

namespace prometheus
{
	void SoundSource::OnInit(std::shared_ptr<Sound> audio)
	{
		sourceID = 0;
		alGenSources(1, &sourceID);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sourceID, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sourceID, AL_BUFFER, audio->bufferId);
	}
	void SoundSource::OnTick()
	{

	}
	void SoundSource::SetAutoRemove(bool aautoRemove)
	{

	}
	void SoundSource::SetAudio(std::shared_ptr<Sound> audio)
	{
		alSourcei(sourceID, AL_BUFFER, audio->bufferId);
	}
	void SoundSource::Play()
	{
		alSourcePlay(sourceID);
	}

}