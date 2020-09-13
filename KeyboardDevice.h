#pragma once

#include "InputSource.h"

using namespace Windows::UI::Core;

class KeyboardDevice
{
public:
	void ReceiveKeyEvent(bool isDown, std::string key);
	InputButtons GetDeviceState();

private:
	std::set<std::string> m_keyState;

};

