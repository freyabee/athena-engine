#include "SoundSource.h"
#include "Sound.h"

namespace prometheus
{
	SoundSource::SoundSource()
	{

	}
	SoundSource::~SoundSource()
	{
	}
	void SoundSource::onInit()
	{
	}
	void SoundSource::onInit(std::shared_ptr<Sound> audio)
	{
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