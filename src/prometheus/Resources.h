#include <memory>
#include <string>
#include <vector>
namespace prometheus
{

	class Core;
	class Resource;


	class Resources
	{	
		friend class Core;

	public:
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
		std::weak_ptr<Core> core;
		std::vector<std::shared_ptr<Resource>> resources;

	};


}