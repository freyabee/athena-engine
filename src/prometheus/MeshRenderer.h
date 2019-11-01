#pragma once
#ifndef _MESHRENDERER_H_
#define _MESHRENDERER_H_
#include <memory>
namespace prometheus
{
	class MeshRenderer
	{
	public:
		MeshRenderer();
		~MeshRenderer();
		
		void onTick();
		void onInit();
	private:
		void onDisplay();
	};


}
#endif // !_MESHRENDERER_H_

