#pragma once
#ifndef _MODEL_H_
#define _MODEL_H_


#include <memory>
#include <rend/rend.h>
#include "Resource.h"


namespace prometheus
{
	/// Model class loads in model information and stores it in local mesh object.
	/// Loads OBJ files from path and stores in rend::Mesh object
	///
	class Model : public Resource
	{
	public:
		/// Loads mesh from path and stores in the Model::mesh variable.
		/// Opens file at path, loads contents to string and passes the data to rend::Mesh::parse()
		/// @param path Path to obj file to be loaded in.
		void Load(std::string path);
		/// Gets the stored mesh object.
		/// Returns pointer to rend::Mesh instance stored in mesh variable.
		/// @returns Pointer to mesh object Model::mesh
		std::shared_ptr<rend::Mesh> GetMesh();
	private:
		/// Pointer to loaded mesh object
		std::shared_ptr<rend::Mesh> mesh;
		/// OBJ data loaded into string
		std::string obj;

	};


}

#endif // !_MODEL_H_