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


	class Sound : public Resource
	{
	public:

		void load(std::string path);
		void play(float volume, float min, float max);
		void play();
	private:
		friend class SoundSource;

		ALuint bufferId;

	};
}
#endif // !_SOUND_H_
