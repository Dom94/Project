#include "Shader.h"

namespace Project
{
	Shader::Shader( std::string vsFilename, std::string fsFilename )
	{
		vertexShaderFilename = vsFilename;
		fragmentShaderFilename = fsFilename;

		loadShader();
		compileShader();
	}

	Shader::~Shader()
	{
	}

	GLuint Shader::loadShader()
	{
		std::ifstream vertexShaderFile( vertexShaderFilename );
		std::ifstream fragmentShaderFile( fragmentShaderFilename );

		vertexShaderSource = "";

		if( vertexShaderFile.is_open() )
		{
			while( vertexShaderFile.good() )
			{
				std::string line;
				std::getline( vertexShaderFile, line );
				vertexShaderSource.append( line + "\n" );
			}
		}
		else
		{
			printf( "Could not open shader file: %s\n", vertexShaderFilename );
			return 0;
		}

		fragmentShaderSource = "";

		if( fragmentShaderFile.is_open() )
		{
			while( fragmentShaderFile.good() )
			{
				std::string line;
				std::getline( fragmentShaderFile, line );
				fragmentShaderSource.append( line + "\n" );
			}
		}
		else
		{
			printf( "Could not open shader file: %s\n", fragmentShaderFilename );
			return 0;
		}

		return GLuint();
	}

	GLuint Shader::compileShader()
	{
		GLuint vertexShaderID = glCreateShader( GL_VERTEX_SHADER );
		GLuint fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );
		programID = glCreateProgram();

		GLint result;
		GLchar infoLog[512];

		//compile the vertex shader
		printf( "Compiling shader: %s\n", vertexShaderFilename.c_str() );
		const char* vertexSourcePointer = vertexShaderSource.c_str();
		glShaderSource( vertexShaderID, 1, &vertexSourcePointer, nullptr );
		glCompileShader( vertexShaderID );

		glGetShaderiv( vertexShaderID, GL_COMPILE_STATUS, &result );
		if( !result )
		{
			glGetShaderInfoLog( vertexShaderID, 512, nullptr, infoLog );
			std::cout << "Vertex shader compilation has failed.\n" << infoLog << std::endl;
		}

		//compile the fragment shader
		printf( "Compiling shader: %s\n", fragmentShaderFilename.c_str() );
		const char* fragmentSourcePointer = fragmentShaderSource.c_str();
		glShaderSource( fragmentShaderID, 1, &fragmentSourcePointer, nullptr );
		glCompileShader( fragmentShaderID );

		glGetShaderiv( fragmentShaderID, GL_COMPILE_STATUS, &result );
		if( !result )
		{
			glGetShaderInfoLog( fragmentShaderID, 512, nullptr, infoLog );
			std::cout << "Fragment shader compilation has failed.\n" << infoLog << std::endl;
		}

		//link the program
		printf( "Linking program\n" );
		glAttachShader( programID, vertexShaderID );
		glAttachShader( programID, fragmentShaderID );
		glLinkProgram( programID );

		glGetProgramiv( programID, GL_LINK_STATUS, &result );
		if( !result )
		{
			glGetProgramInfoLog( programID, 512, nullptr, infoLog );
			std::cout << "Program linking has failed.\n" << infoLog << std::endl;
		}

		//clean up the compiling process
		glDetachShader( programID, vertexShaderID );
		glDetachShader( programID, fragmentShaderID );

		glDeleteShader( vertexShaderID );
		glDeleteShader( fragmentShaderID );

		return programID;
	}

	void Shader::bind()
	{
		glUseProgram( programID );
	}

	void Shader::unbind()
	{
		glUseProgram( 0 );
	}
}