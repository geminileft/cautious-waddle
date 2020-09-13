#include "pch.h"
#include "KeyboardDevice.h"

using namespace std;

void KeyboardDevice::ReceiveKeyEvent(bool isDown, std::string key)
{
	if (isDown)
	{
		m_keyState.insert(key);
	}
	else
	{
		m_keyState.erase(key);
	}
}

InputButtons KeyboardDevice::GetDeviceState()
{
	InputButtons buttonState = InputButtons::None;
	set<string>::iterator keyIter;
	for (keyIter = m_keyState.begin(); keyIter != m_keyState.end(); ++keyIter)
	{
		string keyVal = *keyIter;
		if (keyVal == "Space")
		{
			buttonState = InputButtons::Button3 | buttonState;
		}
		else if (keyVal == "Left")
		{
			buttonState = InputButtons::DPadLeft | buttonState;
		}
		else if (keyVal == "Right")
		{
			buttonState = InputButtons::DPadRight | buttonState;
		}
		else if (keyVal == "Up")
		{
			buttonState = InputButtons::DPadUp | buttonState;
		}
		else if (keyVal == "Down")
		{
			buttonState = InputButtons::DPadDown | buttonState;
		}
		else if (keyVal == "Escape")
		{
			buttonState = InputButtons::Option1 | buttonState;
		}
	}
	return buttonState;
}
