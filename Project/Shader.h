#pragma once

#include <GL\glew.h>

#include <string>
#include <fstream>
#include <iostream>

namespace Project
{
	class Shader
	{
		//functions
	public:
		Shader( std::string vsFilename, std::string fsFilename );
		~Shader();

		GLuint loadShader();
		GLuint compileShader();
		void bind();
		void unbind();

	private:

		//variables
	public:
		GLuint programID;

	private:
		std::string vertexShaderFilename;
		std::string fragmentShaderFilename;

		std::string vertexShaderSource;
		std::string fragmentShaderSource;

	};
}