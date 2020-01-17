#pragma once

#ifndef _RESOURCE_H_
#define _RESOURCE_H_
#include <rend/rend.h>
#include <memory>


namespace prometheus
{
	class Core;
	class Resources;

	/// Parent class for all types of resources in the engine management. 
	/// Inherited from to provide polymorphism when adding multiple types of resources to a resources vector.
	///
	class Resource
	{
		friend class Resources;

	public:

	protected:

		/// Reference to the active core.
		std::weak_ptr<Core> core;

	};
}

#endif // !_RESOURCE_H_