#define GLEW_STATIC

#include "Application.h"

using namespace Project;

int main( int argc, char* argv[] )
{
	//Argument processing here

	Application* engine = new Application();
	engine->run();
	delete engine;

	return 0;
}