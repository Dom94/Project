#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm\gtx\matrix_decompose.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

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
		void setOrientation( glm::float32 angles );
		void setScale( glm::vec2 scale );

		glm::mat4 getLocalMatrix();

		glm::vec2 getPosition();
		glm::quat getRotation();
		glm::vec2 getScale();

		void moveV( float dv );
		void moveH( float dh );
		void rotate( float dr );

	private:

		//variables
	public:
		GameObject* gameObject;

	private:
		glm::mat3 localMatrix;

		glm::vec2 position;
		glm::quat orientation;
		glm::vec2 scale;
	};
}
