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

		b2Vec2 gravity;
		gravity.Set( 0.0f, -30.0f );
		world = new b2World( gravity );

		GameObject* cameraObject = new GameObject();
		renderer->camera = new Camera( CameraType::ORTHOGRAPHIC );
		cameraObject->setCamera( renderer->camera );
		cameraObject->getPhysDef()->setPosition( glm::vec2( 0.0f, 0.0f ) );
		cameraObject->getPhysDef()->setOrientation( 0.0f );
		cameraObject->getPhysDef()->setScale( glm::vec2( 1.0f, 1.0f ) );

		Shader* shader = new Shader( "Assets/Shaders/vertex.ps", "Assets/Shaders/fragment.ps" );

		GameObject* squareObject = new GameObject();
		squareObject->setMeshRenderer( new Square( glm::vec2( 1.0f, 1.0f ) ) );
		squareObject->getPhysDef()->setPosition( glm::vec2( 0.0f, 0.0f ) );
		squareObject->getPhysDef()->setOrientation( 0.0f );
		squareObject->getPhysDef()->setScale( glm::vec2( 1.0f, 1.0f ) );

		b2BodyDef myBodyDef;
		myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
		myBodyDef.position.Set( 0, 30 ); //set the starting position
		myBodyDef.angle = 0; //set the starting angle

		b2PolygonShape boxShape;
		boxShape.SetAsBox( 1, 1 );

		b2FixtureDef boxFixtureDef;
		boxFixtureDef.shape = &boxShape;
		boxFixtureDef.density = 1;

		squareObject->getPhysDef()->setPhysicsBodyDefinition( world, &myBodyDef );
		squareObject->getPhysDef()->setPhysicsFixture( &boxFixtureDef );



		GameObject* squareObject2 = new GameObject();
		squareObject2->setMeshRenderer( new Square( glm::vec2( 3.0f, 1.0f ) ) );
		squareObject2->getPhysDef()->setPosition( glm::vec2( 0.0f, 0.0f ) );
		squareObject2->getPhysDef()->setOrientation( 0.0f );
		squareObject2->getPhysDef()->setScale( glm::vec2( 1.0f, 1.0f ) );

		b2BodyDef myBodyDef2;
		myBodyDef2.type = b2_staticBody; //this will be a dynamic body
		myBodyDef2.position.Set( 0, 0 ); //set the starting position
		myBodyDef2.angle = 0; //set the starting angle

		b2PolygonShape boxShape2;
		boxShape2.SetAsBox( 1, 1 );

		b2FixtureDef boxFixtureDef2;
		boxFixtureDef2.shape = &boxShape2;
		boxFixtureDef2.density = 1;

		squareObject2->getPhysDef()->setPhysicsBodyDefinition( world, &myBodyDef2 );
		squareObject2->getPhysDef()->setPhysicsFixture( &boxFixtureDef2 );





		renderer->shader = shader;
		renderer->square = squareObject;

		objects.push_back( cameraObject );
		objects.push_back( squareObject );

		return true;
	}
}