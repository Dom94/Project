#include "Camera.h"

namespace Project
{
	Camera::Camera( CameraType type, GLfloat fov, GLfloat aspect, GLfloat nearClip, GLfloat farClip )
	{
		this->type = CameraType::PERSPECTIVE;
		this->fov = fov;
		this->aspect = aspect;
		this->nearClip = nearClip;
		this->farClip = farClip;
	}

	Camera::Camera( CameraType type )
	{
		this->type = CameraType::ORTHOGRAPHIC;
	}

	Camera::~Camera()
	{
	}

	glm::mat4 Camera::getView()
	{
		const float *mat = glm::value_ptr( gameObject->getPhysDef()->getLocalMatrix() );

		glm::vec3 eye = glm::vec3( gameObject->getPhysDef()->getPosition(), 0.0f );
		glm::vec3 center = eye + glm::normalize( glm::vec3( mat[8], mat[9], mat[10] ) );
		glm::vec3 up = glm::normalize( glm::vec3( mat[4], mat[5], mat[6] ) );

		return glm::lookAt( eye, center, up );
	}

	glm::mat4 Camera::getProjection()
	{
		if( type == CameraType::PERSPECTIVE )
		{
			return glm::perspective( fov, aspect, nearClip, farClip );
		}
		else if( type == CameraType::ORTHOGRAPHIC )
		{
			return glm::ortho( -(float)WINDOW_WIDTH/20, (float)WINDOW_WIDTH/20, -(float)WINDOW_HEIGHT/20, (float)WINDOW_HEIGHT/20, -1.0f, 1.0f );
		}
	}
}