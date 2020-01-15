#pragma once
#ifndef _AUDIOCONTEXT_H_
#define _AUDIOCONTEXT_H_

#include <AL/al.h>
#include <AL/alc.h>
#include <memory>
namespace prometheus
{
	/// Class encapsulating the raw ALCcontext and ALCdevice.
	///
	/// Initialises and stores ALC context and device pointers and provides access functions.
	class AudioContext
	{
	public:
		/// Initialise AudioContext instance
		///
		/// Creates ALC device and context and assigns to member variables.
		AudioContext();
		~AudioContext();

		/// Returns audio context.
		///
		/// @returns Pointer to ALC context.
		ALCcontext* GetContext();
		/// Returns audio device.
		///
		/// @returns Pointer to ALC device.
		ALCdevice* GetDevice();

	private:
		/// Variable holding ALC context.
		ALCcontext* context;
		/// Variable holding ALC device.
		ALCdevice* device;
		/// Reference to the current instance.
		std::weak_ptr<AudioContext> self;
	};
}
#endif // !_AUDIOCONTEXT_H_
