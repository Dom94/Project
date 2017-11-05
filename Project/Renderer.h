#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <string>
#include <vector>
#include <queue>

#include "Camera.h"
#include "Shader.h"

namespace Project
{
	class Renderer
	{
		//functions
	public:
		Renderer();
		~Renderer();

		void prerender();
		void render();
		void postrender( GLFWwindow* window );

		static void toggleWireframe();

	private:

		//variables
	public:
		Camera* camera;

		Shader* shader;
		GameObject* square;

	private:
		static bool showWireframe;
	};
}