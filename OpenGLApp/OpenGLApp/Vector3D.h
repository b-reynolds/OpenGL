#pragma once
#include "glut.h"

class Vector3D
{

public:
	
	GLfloat x;
	GLfloat y;
	GLfloat z;

	Vector3D(const GLfloat &x, const GLfloat &y, const GLfloat &z);
	Vector3D();

	Vector3D operator+(const Vector3D &vector3D) const;
	Vector3D operator-(const Vector3D &vector3D) const;
	Vector3D operator*(const Vector3D &vector3D) const;
	Vector3D operator*(const GLfloat &scalar) const;
	bool operator==(const Vector3D &vector3D) const;
	bool operator!=(const Vector3D &vector3D) const;


};

