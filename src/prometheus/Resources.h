#include <memory>
#include <string>
#include <vector>
namespace prometheus
{

	class Core;
	class Resource;

	/// Class that stores a pointer to all resources active in scene. 
	/// Resources vector keeps a shared pointer to every active resource in scene.
	/// Keeping a copy in resources ensures there will always be one active reference to the shared pointer, keeping it alive.
	/// The resources vector is a convenient way to store them in memory and have them deleted when going out of scope.
	class Resources
	{	
		friend class Core;

	public:
		/// Template to load resources into resource vector.
		/// Loads resource of type T to resources vector and return the created object with core reference set.
		/// @param path Path of resource to be loaded.
		/// @returns Pointer to resource instance.
		template<typename T>
		std::shared_ptr<T>load(std::string path)
		{
			std::shared_ptr<T>rtn = std::make_shared<T>();
			rtn->core = core;
			rtn->Load(path);
			resources.push_back(rtn);
			return rtn;
		}
	private:
		/// Pointer to current active instance of core.
		std::weak_ptr<Core> core;
		/// Vector of pointers to all resources loaded in scene.
		std::vector<std::shared_ptr<Resource>> resources;

	};


}