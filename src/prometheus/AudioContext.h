#pragma once
#ifndef _AUDIOCONTEXT_H_
#define _AUDIOCONTEXT_H_

#include <AL/al.h>
#include <AL/alc.h>
#include <memory>
namespace prometheus
{
	class AudioContext
	{
	public:
		AudioContext();
		~AudioContext();


	private:
		ALCcontext* context;
		ALCdevice* device;
		std::weak_ptr<AudioContext> self;
	};
}
#endif // !_AUDIOCONTEXT_H_
