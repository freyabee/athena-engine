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

	}
}