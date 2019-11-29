#include "SoundSource.h"
#include "Sound.h"

namespace prometheus
{
	void SoundSource::onInit()
	{
		
		
	}
	void SoundSource::onInit(std::shared_ptr<Sound> audio)
	{
		sourceID = 0;
		alGenSources(1, &sourceID);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sourceID, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sourceID, AL_BUFFER, audio->bufferId);
		alSourcePlay(sourceID);
	}
	void SoundSource::onTick()
	{

	}
	void SoundSource::setAutoRemove(bool _autoRemove)
	{

	}
	void SoundSource::setAudio(std::shared_ptr<Sound> audio)
	{

	}
}