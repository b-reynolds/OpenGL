#pragma once

class Keyboard
{

private:

	static Keyboard* pInstance;
	Keyboard();

	bool prevKeyStates[127] = { false };
	bool keyStates[127] = { false };

public:

	static Keyboard* getInstance();
	
	void setKeyState(unsigned char key, bool state);

	bool isKeyDown(unsigned char key);
	bool isKeyPressed(unsigned char key);

	~Keyboard();

};

