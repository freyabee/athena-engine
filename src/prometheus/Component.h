#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
//Includes
#include <memory>
#include "Entity.h"
class Component
{
public:
	Component();
	~Component();
	
private:
	std::weak_ptr<Entity> entity;
	
};

#endif // !_COMPONENT_H_
