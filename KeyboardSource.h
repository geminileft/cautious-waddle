#pragma once

#include "InputSource.h"
#include "KeyboardDevice.h"

class KeyboardSource :
    public InputSource
{
public:
    KeyboardSource(KeyboardDevice* keyboard);
    InputButtons GetButtonState();

private:
    KeyboardDevice* m_keyboardDevice;
};
