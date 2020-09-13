#pragma once

#include "InputSource.h"

using namespace Windows::Gaming::Input;

class XBoxControllerSource :
    public InputSource
{
public:
    XBoxControllerSource(Gamepad^ gamepad);
    InputButtons GetButtonState();

private:
    Gamepad^ m_gamepad;
};

