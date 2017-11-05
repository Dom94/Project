#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <string>
#include <vector>

#include "Component.h"

namespace Project
{
	struct Vertex
	{
		glm::vec2 position;
		glm::vec2 uvs;
	};

	class MeshRenderer:public Component
	{
		//functions
	public:
		MeshRenderer();
		~MeshRenderer();

		virtual void drawMesh();
		void createBuffers();
		void addVertex( Vertex vertex );
		void addIndex( GLuint index );

	private:

		//variables
	public:
		GameObject* gameObject;

	private:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;

		GLuint VAO, VBO, EBO;
	};
}