#include "AudioContext.h"
#include <AL/al.h>
#include <AL/alc.h>

namespace prometheus
{

	AudioContext::AudioContext()
	{

		//Set device to be new device
		device = alcOpenDevice(NULL);

		//If problem creating new device throw exception
		if (!device)
		{
			throw std::exception();
		}

		//create context passing in device
		context = alcCreateContext(device, NULL);

		//if context not init throw exception
		if (!context)
		{
			alcCloseDevice(device);
			throw std::exception();
		}


		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::exception();
		}



	}
	AudioContext::~AudioContext()
	{
		alcMakeContextCurrent(NULL);
		alcDestroyContext(context);
		alcCloseDevice(device);

	}
	ALCcontext * AudioContext::GetContext()
	{
		return context;	
	}
	ALCdevice * AudioContext::GetDevice()
	{
		return device;
	}
}