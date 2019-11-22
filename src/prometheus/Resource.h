#pragma once

#ifndef _RESOURCE_H_
#define _RESOURCE_H_
#include <rend/rend.h>
#include <memory>


namespace prometheus
{
	class Core;
	class Resources;

	class Resource
	{
		friend class Resources;

	public:

	protected:

		std::weak_ptr<Core> core;

	};
}

#endif // !_RESOURCE_H_