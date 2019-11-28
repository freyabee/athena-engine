#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <string>
#include <memory>
#include "Resource.h"
namespace prometheus
{
	class Sound : public Resource
	{
	public:
		Sound();
		Sound(std::string path);

		void load(std::string path);
		void play(float volume, float min, float max);
		void play();
	private:

	};
}
#endif // !_SOUND_H_
