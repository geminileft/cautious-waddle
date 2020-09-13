#include "pch.h"
#include "XBoxControllerSource.h"

XBoxControllerSource::XBoxControllerSource(Gamepad^ gamepad)
{
	m_gamepad = gamepad;
}

InputButtons XBoxControllerSource::GetButtonState()
{
	InputButtons buttonState = InputButtons::None;
	auto gamepadState = m_gamepad->GetCurrentReading();
	// ArUngYy6i4h5PLrdZH3h7/Z/YSszibkphQwDHweDFJo=
	auto x = m_gamepad->User->NonRoamableId;
	if (gamepadState.Buttons == GamepadButtons::None) {
		return buttonState;
	}

	if ((gamepadState.Buttons & GamepadButtons::B) == GamepadButtons::B)
	{
		buttonState = InputButtons::Button3 | buttonState;
	}
	if ((gamepadState.Buttons & GamepadButtons::DPadLeft) == GamepadButtons::DPadLeft)
	{
		buttonState = InputButtons::DPadLeft | buttonState;
	}
	if ((gamepadState.Buttons & GamepadButtons::DPadRight) == GamepadButtons::DPadRight)
	{
		buttonState = InputButtons::DPadRight | buttonState;
	}
	if ((gamepadState.Buttons & GamepadButtons::DPadDown) == GamepadButtons::DPadDown)
	{
		buttonState = InputButtons::DPadDown | buttonState;
	}
	if ((gamepadState.Buttons & GamepadButtons::DPadUp) == GamepadButtons::DPadUp)
	{
		buttonState = InputButtons::DPadUp | buttonState;
	}
	if ((gamepadState.Buttons & GamepadButtons::View) == GamepadButtons::View)
	{
		buttonState = InputButtons::Option2 | buttonState;
	}
	if ((gamepadState.Buttons & GamepadButtons::Menu) == GamepadButtons::Menu)
	{
		buttonState = InputButtons::Option1 | buttonState;
	}
	return buttonState;
}
