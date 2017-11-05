#pragma once

namespace Project
{
	class GameObject;

	class Component
	{
		//functions
	public:
		Component();
		~Component();

		virtual void update( float dt );
		virtual void init( GameObject* go );

	private:

		//variables
	public:
		GameObject* gameObject;

	private:
	};
}