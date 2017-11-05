#include "GameObject.h"

#include "PhysDef.h"
#include "Component.h"
#include "Camera.h"
#include "MeshRenderer.h"

namespace Project
{
	GameObject::GameObject()
	{
		setPhysDef( new PhysDef() );
		camera = nullptr;
		meshRenderer = nullptr;
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::update( float dt )
	{
		for( int i = 0; i < components.size(); i++ )
		{
			components[i]->update( dt );
		}
	}

	void GameObject::addComponent( Component* c )
	{
		components.push_back( c );
		c->init( this );
	}

	void GameObject::setPhysDef( PhysDef* pd )
	{
		physDef = pd;
		physDef->gameObject = this;
	}

	PhysDef* GameObject::getPhysDef()
	{
		return physDef;
	}

	void GameObject::setCamera( Camera* c )
	{
		camera = c;
		camera->gameObject = this;
	}

	Camera* GameObject::getCamera()
	{
		return camera;
	}

	void GameObject::setMeshRenderer( MeshRenderer* mr )
	{
		meshRenderer = mr;
		meshRenderer->gameObject = this;
	}

	MeshRenderer* GameObject::getMeshRenderer()
	{
		return meshRenderer;
	}
}