#include "Square.h"

namespace Project
{
	Square::Square( float size )
	{
		Vertex vertex1 = {glm::vec2( -0.5f, -0.5f ) * size, glm::vec2( -0.25f, 0.0f )};
		Vertex vertex2 = {glm::vec2( 0.5f, -0.5f ) * size, glm::vec2( -0.25f, 0.0f )};
		Vertex vertex3 = {glm::vec2( -0.5f, 0.5f ) * size, glm::vec2( -0.25f, 0.0f )};

		Vertex vertex4 = {glm::vec2( 0.5f, -0.5f ) * size, glm::vec2( -0.25f, 0.0f )};
		Vertex vertex5 = {glm::vec2( 0.5f, 0.5f ) * size, glm::vec2( -0.25f, 0.0f )};
		Vertex vertex6 = {glm::vec2( -0.5f, 0.5f ) * size, glm::vec2( -0.25f, 0.0f )};

		addVertex( vertex1 );
		addVertex( vertex2 );
		addVertex( vertex3 );
		addVertex( vertex4 );
		addVertex( vertex5 );
		addVertex( vertex6 );

		addIndex( 0 );
		addIndex( 1 );
		addIndex( 2 );
		addIndex( 3 );
		addIndex( 4 );
		addIndex( 5 );

		createBuffers();
	}

	Square::~Square()
	{
	}
}
