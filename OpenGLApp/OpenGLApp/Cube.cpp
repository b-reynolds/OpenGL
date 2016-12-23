#include "Cube.h" 

Cube::Cube(const Vector3D &position, const Vector3D &size)
{
	this->position = position;
	this->size = size;
}

Cube::Cube()
{
	position = Vector3D(0, 0, 0);
	size = Vector3D(0, 0, 0);
}

void Cube::draw()
{
	// Load the identity matrix
	glLoadIdentity();

	// Set the cube's position
	glTranslatef(position.x, position.y, position.z); 

	// Set the cube's orientation
	glRotatef(orientation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(orientation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(orientation.z, 0.0f, 0.0f, 1.0f);

	// Draw the cube
	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);     // Green

	// Top face
	glVertex3f(size.x, size.y, -size.z);
	glVertex3f(-size.x, size.y, -size.z);
	glVertex3f(-size.x, size.y, size.z);
	glVertex3f(size.x, size.y, size.z);

	glColor3f(1.0f, 0.5f, 0.0f);     // Orange

	// Bottom face
	glVertex3f(size.x, -size.y, size.z);
	glVertex3f(-size.x, -size.y, size.z);
	glVertex3f(-size.x, -size.y, -size.z);
	glVertex3f(size.x, -size.y, -size.z);

	glColor3f(1.0f, 0.0f, 0.0f);     // Red

	// Front face
	glVertex3f(size.x, size.y, size.z);
	glVertex3f(-size.x, size.y, size.z);
	glVertex3f(-size.x, -size.y, size.z);
	glVertex3f(size.x, -size.y, size.z);

	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow

	// Back face
	glVertex3f(size.x, -size.y, -size.z);
	glVertex3f(-size.x, -size.y, -size.z);
	glVertex3f(-size.x, size.y, -size.z);
	glVertex3f(size.x, size.y, -size.z);

	glColor3f(0.0f, 0.0f, 1.0f);     // Blue

	// Left face
 	glVertex3f(-size.x, size.y, size.z);
	glVertex3f(-size.x, size.y, -size.z);
	glVertex3f(-size.x, -size.y, -size.z);
	glVertex3f(-size.x, -size.y, size.z);

	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta

	// Right face
	glVertex3f(size.x, size.y, -size.z);
	glVertex3f(size.x, size.y, size.z);
	glVertex3f(size.x, -size.y, size.z);
	glVertex3f(size.x, -size.y, -size.z);

	glEnd();
}

void Cube::setPosition(const Vector3D &position)
{
	this->position = position;
}

void Cube::setSize(const Vector3D &size)
{
	this->size = size;
}

void Cube::setOrientation(const Vector3D& orientation)
{
	this->orientation = orientation;
}

void Cube::rotate(const Vector3D& orientation)
{
	this->orientation = this->orientation + orientation;
}
