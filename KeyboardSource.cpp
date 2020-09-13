#include "pch.h"
#include "KeyboardSource.h"

KeyboardSource::KeyboardSource(KeyboardDevice* keyboard)
{
	m_keyboardDevice = keyboard;
}

InputButtons KeyboardSource::GetButtonState()
{
	return m_keyboardDevice->GetDeviceState();
}
