#pragma once

#include "KeyboardDevice.h"
#include "InputSource.h"
#include <vector>

using namespace Windows::UI::Core;
using namespace Windows::System;
using namespace std;

class InputSourceManager
{
public:
	static InputSourceManager* InitPlatformManager(CoreWindow^ window);
	void AddSource(InputSource* source);
	vector<InputSource*> GetSources();

private:
	InputSourceManager() {};


	/// <summary>
	/// This class is needed by CoreWindow to be the event
	/// handler delegate. It is used to forward the events
	/// to the input manager.
	/// </summary>
	ref class PlatformInputForwarder sealed
	{
	public:
		void OnKeyDown(
			CoreWindow^ sender,
			KeyEventArgs^ args
		);
		void OnKeyUp(
			CoreWindow^ sender,
			KeyEventArgs^ args
		);

	private:
		KeyboardDevice* m_keyboardDevice;

		static string VirtualKeyToString(VirtualKey key);

	internal:
		PlatformInputForwarder(CoreWindow^ window);
		KeyboardDevice* GetKeyboardDevice();

	};

	InputSourceManager::PlatformInputForwarder^ m_inputForwarder;
	vector<InputSource*> m_inputSources;

};
