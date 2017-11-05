#pragma once

#include <vector>

namespace Project
{
	class PhysDef;
	class Component;
	class Camera;
	class MeshRenderer;

	class GameObject
	{
		//functions
	public:
		GameObject();
		~GameObject();

		void update( float dt );

		void addComponent( Component* c );

		void setPhysDef( PhysDef* p );
		PhysDef* getPhysDef();

		void setCamera( Camera* c );
		Camera* getCamera();

		void setMeshRenderer( MeshRenderer* c );
		MeshRenderer* getMeshRenderer();

	private:

		//variables
	public:
		PhysDef* physDef;
		Camera* camera;
		MeshRenderer* meshRenderer;

	private:
		std::vector<Component*> components;
	};
}