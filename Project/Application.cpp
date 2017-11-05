#include "Application.h"

#include "GameObject.h"
#include "PhysDef.h"

#include "Shader.h"
#include "MeshRenderer.h"
#include "Square.h"

namespace Project
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	bool Application::init()
	{
		Engine::init();

		GameObject* cameraObject = new GameObject();
		renderer->camera = new Camera( CameraType::ORTHOGRAPHIC );
		cameraObject->setCamera( renderer->camera );
		cameraObject->getPhysDef()->setPosition( glm::vec2( 0.0f, 0.0f ) );
		cameraObject->getPhysDef()->setOrientation( 0.0f );
		cameraObject->getPhysDef()->setScale( glm::vec2( 1.0f, 1.0f ) );

		Shader* shader = new Shader( "Assets/Shaders/vertex.ps", "Assets/Shaders/fragment.ps" );

		GameObject* squareObject = new GameObject();
		squareObject->setMeshRenderer( new Square( 100 ) );
		squareObject->getPhysDef()->setPosition( glm::vec2( 0.0f, 0.0f ) );
		squareObject->getPhysDef()->setOrientation( 0.0f );
		squareObject->getPhysDef()->setScale( glm::vec2( 1.0f, 1.0f ) );

		renderer->shader = shader;
		renderer->square = squareObject;

		objects.push_back( cameraObject );
		objects.push_back( squareObject );

		return true;
	}
}