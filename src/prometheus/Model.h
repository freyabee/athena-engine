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

		void Load(std::string path);
		std::shared_ptr<rend::Mesh> GetMesh();
	private:
		std::shared_ptr<rend::Mesh> mesh;
		std::string obj;

	};


}

#endif // !_MODEL_H_