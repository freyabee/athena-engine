#pragma once
#ifndef _MODEL_H_
#define _MODEL_H_


#include <memory>
#include <rend/rend.h>
#include "Resource.h"


namespace prometheus
{
	class Model : public Resource
	{
	public:

		void load(std::string path);
		std::shared_ptr<rend::Mesh> getMesh();
	private:
		std::shared_ptr<rend::Mesh> mesh;
		
		const char* obj =
			"v -1 1 0           \n" \
			"v -1 -1 0          \n" \
			"v 1 -1 0           \n" \
			"v 1 1 0            \n" \
			"                   \n" \
			"vt 0 1             \n" \
			"vt 0 0             \n" \
			"vt 1 0             \n" \
			"vt 1 1             \n" \
			"                   \n" \
			"f 1/1 2/2 3/3 4/4  \n" \
			"                   \n";

	};


}

#endif // !_MODEL_H_