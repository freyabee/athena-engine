#pragma once

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <vector>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	bool getKey(int _keyCode);
	bool getKeyDown(int _keyCode);
	bool getKeyUp(int _keyCode);

private:
	std::vector<int> keyCodes;

};

#endif // !_KEYBOARD_H_