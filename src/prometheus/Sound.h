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

		void Load(std::string path);
		void Play(float volume, float min, float max);
		void Play();
	private:
		friend class SoundSource;

		ALuint bufferId;

	};
}
#endif // !_SOUND_H_
