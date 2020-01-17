#ifndef _SOUNDSOURCE_H_
#define _SOUNDSOURCE_H_


#include "Component.h"
#include <AL/al.h>
#include <AL/alc.h>


namespace prometheus
{
	class Sound;
	/// Sound component that allows sounds to be attached to entities.
	class SoundSource : public Component
	{
	public:
		/// Initialise soundsource with audio parameter audio.
		/// Takes a pointer to a Sound instance and loads it into OpenAL buffer.
		void OnInit(std::shared_ptr<Sound> audio);
		/// SoundSource OnTick() function, overloaded from componenet.
		void OnTick();
		void SetAutoRemove(bool autoRemove);
		/// Set buffer using buffer from soundsource audio.
		/// @param audio Pointer to Sound instance, contains audio buffer.
		void SetAudio(std::shared_ptr<Sound> audio);
		/// Plays loaded audio
		void Play();
	private:
		bool autoRemove;
		/// Buffer ID
		ALuint sourceID;

	};
}
#endif // !_SOUNDSOURCE_H_
