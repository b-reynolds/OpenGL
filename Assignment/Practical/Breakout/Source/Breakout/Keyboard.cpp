#include "Keyboard.h"

Keyboard* Keyboard::pInstance = nullptr;

Keyboard::Keyboard()
{
}

Keyboard* Keyboard::getInstance()
{
	if(pInstance == nullptr)
	{
		pInstance = new Keyboard();
	}
	return pInstance;
}

void Keyboard::setKeyState(unsigned char key, bool state)
{
	prevKeyStates[key] = keyStates[key];
	keyStates[key] = state;
}

bool Keyboard::isKeyDown(unsigned char key)
{
	return keyStates[key];
}

bool Keyboard::isKeyPressed(unsigned char key)
{
	return keyStates[key] && !prevKeyStates[key];
}

Keyboard::~Keyboard()
{
	delete pInstance;
}
