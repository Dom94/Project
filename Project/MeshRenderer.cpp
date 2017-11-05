#include "MeshRenderer.h"

namespace Project
{
	MeshRenderer::MeshRenderer()
	{
	}

	MeshRenderer::~MeshRenderer()
	{
	}

	void MeshRenderer::drawMesh()
	{
		glBindVertexArray( VAO );
		glDrawElements( GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );
	}

	void MeshRenderer::createBuffers()
	{
		glGenVertexArrays( 1, &VAO );
		glGenBuffers( 1, &VBO );
		glGenBuffers( 1, &EBO );

		glBindVertexArray( VAO );

		glBindBuffer( GL_ARRAY_BUFFER, VBO );
		glBufferData( GL_ARRAY_BUFFER, vertices.size() * sizeof( Vertex ), &vertices[0], GL_STATIC_DRAW );

		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof( GLuint ), &indices[0], GL_STATIC_DRAW );

		glEnableVertexAttribArray( 0 );
		glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (GLvoid*)0 );

		glEnableVertexAttribArray( 1 );
		glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (GLvoid*)offsetof( Vertex, uvs ) );

		glBindVertexArray( 0 );
	}

	void MeshRenderer::addVertex( Vertex vertex )
	{
		vertices.push_back( vertex );
	}

	void MeshRenderer::addIndex( GLuint index )
	{
		indices.push_back( index );
	}
}