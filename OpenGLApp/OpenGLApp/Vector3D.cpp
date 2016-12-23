#include "Vector3D.h"  

Vector3D::Vector3D(const GLfloat &x, const GLfloat &y, const GLfloat &z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3D Vector3D::operator+(const Vector3D &vector3D) const
{
	return Vector3D(x + vector3D.x, y + vector3D.y, z + vector3D.z);
}

Vector3D Vector3D::operator-(const Vector3D &vector3D) const
{
	return Vector3D(x - vector3D.x, y - vector3D.y, z - vector3D.z);
}

Vector3D Vector3D::operator*(const Vector3D &vector3D) const
{
	return Vector3D(x * vector3D.x, y * vector3D.y, z * vector3D.z);
}

Vector3D Vector3D::operator*(const GLfloat &scalar) const
{
	return Vector3D(x * scalar, y * scalar, z * scalar);
}
