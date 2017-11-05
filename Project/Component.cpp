#include "Component.h"

namespace Project
{
	Component::Component()
	{
	}

	Component::~Component()
	{
	}

	void Component::update( float dt )
	{
	}

	void Component::init( GameObject* go )
	{
		gameObject = go;
	}
}