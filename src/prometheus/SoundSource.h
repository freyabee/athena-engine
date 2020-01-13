#ifndef _SOUNDSOURCE_H_
#define _SOUNDSOURCE_H_


#include "Component.h"
#include <AL/al.h>
#include <AL/alc.h>


namespace prometheus
{
	class Sound;

	class SoundSource : public Component
	{
	public:
		void OnInit();
		void OnInit(std::shared_ptr<Sound> audio);
		void OnTick();
		void setAutoRemove(bool _autoRemove);
		void setAudio(std::shared_ptr<Sound> audio);

	private:
		bool autoRemove;
		ALuint sourceID;

	};
}
#endif // !_SOUNDSOURCE_H_
