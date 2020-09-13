#pragma once

enum class InputButtons : long
{
	None = 0,
	DPadLeft = 1,
	DPadRight = 2,
	DPadUp = 4,
	DPadDown = 8,
	Button0 = 16,
	Button1 = 32,
	Button2 = 64,
	Button3 = 128,
	LeftStick = 256,
	RightStick = 512,
	Option1 = 1024,
	Option2 = 2048,
	LeftShoulder1 = 4096,
	LeftShoulder2 = 8192,
	RightShoulder1 = 16384,
	RightShoulder2 = 32768

};

inline InputButtons operator |(InputButtons a, InputButtons b)
{
	return static_cast<InputButtons>(static_cast<long>(a) | static_cast<long>(b));
}

inline InputButtons operator &(InputButtons a, InputButtons b)
{
	return static_cast<InputButtons>(static_cast<long>(a) & static_cast<long>(b));
}

class InputSource
{
public:

	virtual InputButtons GetButtonState() = 0;
};

