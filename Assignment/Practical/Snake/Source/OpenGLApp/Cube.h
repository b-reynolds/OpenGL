#pragma once
#include "Vector3D.h"
#include "Texture2D.h"

class Cube
{

public:

	Cube(const Vector3D &position, const Vector3D &size, Texture2D &texture);
	Cube(const Vector3D &position, const Vector3D &size);
	Cube();

	void draw();
	
	void setPosition(const Vector3D &position);
	Vector3D getPosition() const;

	void setSize(const Vector3D &size);
	Vector3D getSize() const;

	void setRotation(const Vector3D &rotation);
	Vector3D getRotation() const;

	void rotate(const Vector3D &orientation);
	void move(const Vector3D &velocity);

private:

	Texture2D texture;

	Vector3D position;
	Vector3D size;
	Vector3D rotation;

};

