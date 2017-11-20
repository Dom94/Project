#pragma once

#define GLFW_DLL
//#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <Box2D\Box2D.h>

#include <iostream>

#include "Renderer.h"

namespace Project
{
	#define WINDOW_WIDTH 800
	#define WINDOW_HEIGHT 600

	void key_callback( GLFWwindow* window, int key, int scancode, int action, int mode );
	void mPos_callback( GLFWwindow* window, double xpos, double ypos );
	void mButton_callback( GLFWwindow* window, int button, int action, int mods );
	void mScroll_callback( GLFWwindow* window, double xoffset, double yoffset );

	class Engine
	{
		//functions
	public:
		Engine();
		~Engine();

		virtual bool init();
		virtual void run();

	private:
		void updateComponents();

		void calculateFPS();

		bool setupExtensions();
		bool setupRenderer();

		//variables
	private:
		char fps[15];
		int frameCount;
		float thisFrame;
		float lastFrame;
		float dtLastFrame;
		float dt;

	public:
		Renderer* renderer;
		GLFWwindow* window;

		std::vector<GameObject*> objects;
		b2World* world;
	};
}