#include "Cube.h" 

Cube::Cube(const Vector3D& position, const Vector3D& size, Texture2D &texture)
{
	this->position = position;
	this->size = size;
	this->texture = texture;
}

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
	glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

	if(texture.isLoaded())
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture.getTexture());
	}

	// Draw the cube
	glBegin(GL_QUADS);

	// Top face
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(size.x, size.y, -size.z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-size.x, size.y, -size.z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-size.x, size.y, size.z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(size.x, size.y, size.z);  

	// Bottom face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(size.x, -size.y, size.z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-size.x, -size.y, size.z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-size.x, -size.y, -size.z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(size.x, -size.y, -size.z);

	// Front face
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(size.x, size.y, size.z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-size.x, size.y, size.z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-size.x, -size.y, size.z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(size.x, -size.y, size.z);     

	// Back face
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(size.x, -size.y, -size.z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-size.x, -size.y, -size.z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-size.x, size.y, -size.z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(size.x, size.y, -size.z);   

	// Left face
	glTexCoord2f(0.0f, 0.0f);
 	glVertex3f(-size.x, size.y, size.z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-size.x, size.y, -size.z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-size.x, -size.y, -size.z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-size.x, -size.y, size.z);

	// Right face
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(size.x, size.y, -size.z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(size.x, size.y, size.z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(size.x, -size.y, size.z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(size.x, -size.y, -size.z);

	glEnd();

	if(texture.isLoaded())
	{
		glDisable(GL_TEXTURE_2D);
	}
}

void Cube::setPosition(const Vector3D &position)
{
	this->position = position;
}

Vector3D Cube::getPosition() const
{
	return position;
}

void Cube::setSize(const Vector3D &size)
{
	this->size = size;
}

Vector3D Cube::getSize() const
{
	return size;
}

void Cube::setRotation(const Vector3D& rotation)
{
	this->rotation = rotation;
}

Vector3D Cube::getRotation() const
{
	return rotation;
}

void Cube::rotate(const Vector3D& rotation)
{
	this->rotation = this->rotation + rotation;
}

void Cube::move(const Vector3D& velocity)
{
	position = position + velocity;
}
