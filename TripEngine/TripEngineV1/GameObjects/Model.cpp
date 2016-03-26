#include "Model.h"
#include "Vertex.h"
#include "..\Import\OBJImporter.h"

using namespace TripEngine;
using namespace GameObjects;

Model::Model(const char* path) : GameObject()
{
	std::vector<Vertex> vertices;

	Import::OBJImporter::ImportOBJ(path, vertices);

	numVertices = vertices.size();

	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numVertices, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, Vertex::texcoord)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, Vertex::normal)));

	glBindVertexArray(0);

	this->vao = vao;
	this->vbos.push_back(vbo);
}

Model::~Model()
{

}

void Model::Draw(const glm::vec3& viewPos, const glm::vec3& lightPos, const glm::vec4& ambientColor)
{
	glUseProgram(program);

	glUniformMatrix4fv(glGetUniformLocation(program, "modelMatrix"), 1, false, &transformMatrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "viewMatrix"), 1, false, &(*viewMatrix)[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projectionMatrix"), 1, false, &(*projectionMatrix)[0][0]);

	glUniform3fv(glGetUniformLocation(program, "viewPosition"), 1, &viewPos[0]);
	glUniform3fv(glGetUniformLocation(program, "lightPosition"), 1, &lightPos[0]);
	glUniform4fv(glGetUniformLocation(program, "ambient"), 1, &ambientColor[0]);

	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, numVertices);
}

void Model::SetProgram(GLuint program)
{
	this->program = program;
}

GLuint Model::GetVao()
{
	return vao;
}

const std::vector<GLuint>& Model::GetVbos()
{
	return vbos;
}

void Model::SetViewMatrix(glm::mat4* matrix)
{
	viewMatrix = matrix;
}

void Model::SetProjectionMatrix(glm::mat4* matrix)
{
	projectionMatrix = matrix;
}