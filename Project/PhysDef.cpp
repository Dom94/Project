#include "PhysDef.h"

#include <iostream>

namespace Project
{
	PhysDef::PhysDef()
	{
		localMatrix = glm::mat3( 1.0f );

		physicsBodyDefinition = nullptr;
		physicsBody = nullptr;
	}

	PhysDef::~PhysDef()
	{
	}

	void PhysDef::setPosition( glm::vec2 pos )
	{
		position = pos;
	}

	void PhysDef::setOrientation( glm::float32 angle )
	{
		glm::quat newRotation = glm::angleAxis( glm::radians( angle ), glm::vec3( 0, 0, 1 ) );
		orientation = newRotation;
	}

	void PhysDef::setScale( glm::vec2 sca )
	{
		scale = sca;
	}

	glm::mat4 PhysDef::getLocalMatrix()
	{
		glm::mat4 translationMatrix;
		glm::mat4 rotationMatrix;
		glm::mat4 scaleMatrix;

		if( physicsBody != nullptr )
		{
			//std::cout << physicsBody->GetPosition().y << std::endl;
			translationMatrix = glm::translate( glm::mat4( 1.0f ), glm::vec3( glm::vec2( physicsBody->GetPosition().x, physicsBody->GetPosition().y ), 0.0f ) );
			rotationMatrix = glm::mat4_cast( glm::angleAxis( physicsBody->GetAngle(), glm::vec3( 0, 0, 1 ) ) );
			scaleMatrix = glm::scale( glm::mat4( 1.0f ), glm::vec3( scale, 1.0f ) );
		}
		else
		{
			translationMatrix = glm::translate( glm::mat4( 1.0f ), glm::vec3( position, 0.0f ) );
			rotationMatrix = glm::mat4_cast( orientation );
			scaleMatrix = glm::scale( glm::mat4( 1.0f ), glm::vec3( scale, 1.0f ) );
		}

		return translationMatrix * rotationMatrix * scaleMatrix;
	}

	glm::vec2 PhysDef::getPosition()
	{
		if( physicsBody != nullptr )
		{
			position = glm::vec2( physicsBody->GetPosition().x, physicsBody->GetPosition().y );
		}

		return position;
	}

	glm::quat PhysDef::getRotation()
	{
		return orientation;
	}

	glm::vec2 PhysDef::getScale()
	{
		return scale;
	}

	void PhysDef::setPhysicsBodyDefinition( b2World* world, b2BodyDef* pbd )
	{
		physicsBodyDefinition = pbd;

		physicsBody = world->CreateBody( physicsBodyDefinition );
	}

	b2BodyDef* PhysDef::getPhysicsBodyDefinition()
	{
		return physicsBodyDefinition;
	}

	void PhysDef::setPhysicsFixture( b2FixtureDef* fd )
	{
		if( physicsBody != nullptr )
		{
			physicsFixture = fd;

			physicsBody->CreateFixture( physicsFixture );
		}
	}

	b2FixtureDef* PhysDef::getPhysicsFixture()
	{
		return physicsFixture;
	}

	void PhysDef::moveV( float dv )
	{
		position = position + glm::vec2( 0.0f, 1.0f ) * dv;
	}

	void PhysDef::moveH( float dh )
	{
		position = position + glm::vec2( 1.0f, 0.0f ) * dh;
	}

	void PhysDef::rotate( float dr )
	{
		orientation = orientation * glm::angleAxis( dr, glm::vec3( 0, 0, 1 ) );
	}
}