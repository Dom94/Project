#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm\gtx\matrix_decompose.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <Box2D\Box2D.h>

#include <vector>

namespace Project
{
	class GameObject;

	class PhysDef
	{
		//functions
	public:
		PhysDef();
		~PhysDef();

		void setPosition( glm::vec2 position );
		glm::vec2 getPosition();

		void setOrientation( glm::float32 angles );
		glm::quat getRotation();

		void setScale( glm::vec2 scale );
		glm::vec2 getScale();

		void setPhysicsBodyDefinition( b2World* w, b2BodyDef* bd );
		b2BodyDef* getPhysicsBodyDefinition();

		void setPhysicsFixture( b2FixtureDef* fd );
		b2FixtureDef* getPhysicsFixture();

		glm::mat4 getLocalMatrix();

		void moveV( float dv );
		void moveH( float dh );
		void rotate( float dr );

	private:

		//variables
	public:
		GameObject* gameObject;

	private:
		b2BodyDef* physicsBodyDefinition;
		b2Body* physicsBody;
		b2FixtureDef* physicsFixture;

		glm::mat3 localMatrix;

		glm::vec2 position;
		glm::quat orientation;
		glm::vec2 scale;
	};
}
