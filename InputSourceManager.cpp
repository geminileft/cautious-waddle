#include "pch.h"
#include "InputSourceManager.h"
#include "KeyboardSource.h"
#include "XBoxControllerSource.h"
#include <collection.h>

using namespace Windows::System;
using namespace Windows::Gaming::Input;
using namespace Windows::Foundation;

InputSourceManager* InputSourceManager::InitPlatformManager(CoreWindow^ window)
{
	InputSourceManager* sourceManager = new InputSourceManager();
    sourceManager->m_inputForwarder = ref new InputSourceManager::PlatformInputForwarder(window);
    sourceManager->AddSource(new KeyboardSource(sourceManager->m_inputForwarder->GetKeyboardDevice()));
    for (auto gamepad : Gamepad::Gamepads)
    {
        sourceManager->AddSource(new XBoxControllerSource(gamepad));
    }

    Gamepad::GamepadAdded += ref new EventHandler<Gamepad^>([=](Platform::Object^, Gamepad^ args)
    {
            sourceManager->AddSource(new XBoxControllerSource(args));
    });

    Gamepad::GamepadRemoved += ref new EventHandler<Gamepad^>([=](Platform::Object^, Gamepad^ args)
    {
            //TODO: SOMETHING HERE...
    });

	return sourceManager;
}

void InputSourceManager::AddSource(InputSource* source)
{
    m_inputSources.push_back(source);
}

vector<InputSource*> InputSourceManager::GetSources()
{
    return m_inputSources;
}

InputSourceManager::PlatformInputForwarder::PlatformInputForwarder(CoreWindow^ window)
{
    window->KeyDown +=
        ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &InputSourceManager::PlatformInputForwarder::OnKeyDown);

    window->KeyUp +=
        ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &InputSourceManager::PlatformInputForwarder::OnKeyUp);

    m_keyboardDevice = new KeyboardDevice();
}

void InputSourceManager::PlatformInputForwarder::OnKeyDown(CoreWindow^ sender, KeyEventArgs^ args)
{
    auto inputKey = args->VirtualKey;
    std::string keyValue = VirtualKeyToString(inputKey);

    // only proceed of we have a value we are interested in
    if (keyValue.empty())
        return;

    m_keyboardDevice->ReceiveKeyEvent(true, keyValue);
}

void InputSourceManager::PlatformInputForwarder::OnKeyUp(CoreWindow^ sender, KeyEventArgs^ args)
{
    //LARGE_INTEGER currentTimestamp;
    //QueryPerformanceCounter(&currentTimestamp);

    auto inputKey = args->VirtualKey;
    std::string keyValue = VirtualKeyToString(inputKey);

    // only proceed of we have a value we are interested in
    if (keyValue.empty())
        return;

    m_keyboardDevice->ReceiveKeyEvent(false, keyValue);

}

std::string InputSourceManager::PlatformInputForwarder::VirtualKeyToString(VirtualKey key)
{
    std::wstring tempWString(key.ToString()->Begin());
    std::string keyValue(tempWString.begin(), tempWString.end());
    return keyValue;
}

KeyboardDevice* InputSourceManager::PlatformInputForwarder::GetKeyboardDevice()
{
    return m_keyboardDevice;
}

