#pragma once
#include "Vector3D.h"

class Cube
{

public:

	Cube(const Vector3D &position, const Vector3D &size);
	Cube();

	void draw();
	
	void setPosition(const Vector3D &position);
	void setSize(const Vector3D &size);
	void setOrientation(const Vector3D &orientation);
	void rotate(const Vector3D &orientation);

private:

	Vector3D position;
	Vector3D size;
	Vector3D orientation;

};

