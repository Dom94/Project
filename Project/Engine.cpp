#include "Engine.h"

namespace Project
{
	Engine::Engine()
	{
		renderer = nullptr;
		window = nullptr;
	}

	Engine::~Engine()
	{
		glfwTerminate();
	}

	bool Engine::init()
	{
		std::cout << "Initialising the engine" << std::endl;

		if( setupExtensions() == false )
		{
			std::cout << "Could not initialise the extensions" << std::endl;
			return false;
		}

		if( setupRenderer() == false )
		{
			std::cout << "Could not initialise the renderer" << std::endl;
			return false;
		}

		return true;
	}

	void Engine::run()
	{
		//initialise the engine and extensions (glfw/glew)
		if( init() == false )
		{
			std::cout << "Could not initialise the engine" << std::endl;
			return;
		}

		//Core engine loop
		while( !glfwWindowShouldClose( window ) )
		{
			calculateFPS();

			//hangle events (user input etc)
			glfwPollEvents();

			//Render loop
			renderer->prerender();
			renderer->render();
			renderer->postrender( window );
		}

		//TODO: MOVE TO EXTENSION CLEANUP
		glfwTerminate();
	}

	void Engine::calculateFPS()
	{
		//calculate the frame delta and fps
		thisFrame = glfwGetTime();

		dt = thisFrame - dtLastFrame;
		dtLastFrame = thisFrame;
	}

	bool Engine::setupExtensions()
	{
		if( !glfwInit() )
		{
			std::cout << "Could not initialise glfw3" << std::endl;
			return false;
		}

		//specify the OpenGL version so that legacy functions throw errors
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
		glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

		//create a window and context for rendering
		window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Project", NULL, NULL );
		if( window == nullptr )
		{
			std::cout << "Could not create window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent( window );

		//initialise all of the OpenGL functions
		glewExperimental = GL_TRUE;
		if( glewInit() != GLEW_OK )
		{
			std::cout << "Could not initialise GLEW" << std::endl;
			return false;
		}

		//create/define the viewport - TODO: MOVE TO RENDERER INIT
		int width;
		int height;
		glfwGetFramebufferSize( window, &width, &height );
		glViewport( 0, 0, width - 50, height - 50 );

		//assign all of the callbacks - TODO: MOVE TO INPUT INIT
		glfwSetKeyCallback( window, key_callback );
		glfwSetCursorPosCallback( window, mPos_callback );
		glfwSetMouseButtonCallback( window, mButton_callback );
		glfwSetScrollCallback( window, mScroll_callback );
		glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR );
		glfwSetCursorPos( window, 0, 0 );

		return true;
	}

	bool Engine::setupRenderer()
	{
		renderer = new Renderer();

		//TODO: SETUP CHECK

		return true;
	}

	void key_callback( GLFWwindow* window, int key, int scancode, int action, int mode )
	{
		if( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
		{
			glfwSetWindowShouldClose( window, GL_TRUE );
		}

		if( key == GLFW_KEY_F2 && action == GLFW_PRESS )
		{
			Renderer::toggleWireframe();
		}
	}

	void mPos_callback( GLFWwindow* window, double xpos, double ypos )
	{
	}

	void mButton_callback( GLFWwindow* window, int button, int action, int mods )
	{
	}

	void mScroll_callback( GLFWwindow* window, double xoffset, double yoffset )
	{
	}
}