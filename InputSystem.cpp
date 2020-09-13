#include "pch.h"
#include "InputSystem.h"

InputSystem::InputSystem(InputSourceManager* inputManager)
{
	m_inputManager = inputManager;
}

void InputSystem::Update(DX::StepTimer const& timer)
{
	m_currentButtons = InputButtons::None;
	for (auto source : m_inputManager->GetSources())
	{
		auto buttonState = source->GetButtonState();
		if (buttonState != InputButtons::None)
		{
			m_currentButtons = buttonState;
			return;
		}
	}
}

InputButtons InputSystem::GetButtons()
{
	return m_currentButtons;
}
