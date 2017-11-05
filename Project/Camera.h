#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Component.h"
#include "GameObject.h"
#include "PhysDef.h"

namespace Project
{
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

	enum CameraType
	{
		ORTHOGRAPHIC,
		PERSPECTIVE
	};

	class Camera:public Component
	{
	public:
		Camera( CameraType type, GLfloat fov, GLfloat aspect, GLfloat nearClip, GLfloat farClip );
		Camera( CameraType type );
		~Camera();

		glm::mat4 getView();
		glm::mat4 getProjection();

	private:

		//variables
	public:

	private:
		CameraType type;
		GLfloat fov;
		GLfloat aspect;
		GLfloat nearClip;
		GLfloat farClip;
	};
}