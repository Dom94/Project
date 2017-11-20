#include "Renderer.h"

#include "GameObject.h"
#include "PhysDef.h"

#include "MeshRenderer.h"

namespace Project
{
	bool Renderer::showWireframe = false;

	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::prerender()
	{
		//clear the screen
		glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		showWireframe == true ? glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ) : glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

		glDisable( GL_DEPTH_TEST );

		glPointSize( 4.0f );
		glLineWidth( 1 );
	}

	void Renderer::render()
	{
		glm::mat4 model;
		glm::mat4 view = camera->getView();
		glm::mat4 projection = camera->getProjection();

		shader->bind();

		GLint modelLocation = glGetUniformLocation( shader->programID, "model" );
		GLint viewLocation = glGetUniformLocation( shader->programID, "view" );
		GLint projectionLocation = glGetUniformLocation( shader->programID, "projection" );

		glUniformMatrix4fv( projectionLocation, 1, GL_FALSE, glm::value_ptr( projection ) );

		model = square->getPhysDef()->getLocalMatrix();
		std::cout << square->getPhysDef()->getPosition().y << std::endl;
		glUniformMatrix4fv( modelLocation, 1, GL_FALSE, glm::value_ptr( model ) );
		glUniformMatrix4fv( viewLocation, 1, GL_FALSE, glm::value_ptr( view ) );
		glUniformMatrix4fv( projectionLocation, 1, GL_FALSE, glm::value_ptr( projection ) );

		GLint colorLocation = glGetUniformLocation( shader->programID, "spriteColor" );

		glUniform3f( colorLocation, 1.0f, 0.0f, 0.0f );

		square->getMeshRenderer()->drawMesh();

		shader->unbind();
	}

	void Renderer::postrender( GLFWwindow* window )
	{
		//swap the color buffer and display it on the screen
		glfwSwapBuffers( window );
	}

	void Renderer::toggleWireframe()
	{
		showWireframe = !showWireframe;
	}
}