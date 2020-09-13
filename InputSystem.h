#pragma once

#include "InputSourceManager.h"
#include <Common\StepTimer.h>

class InputSystem
{
public:
	InputSystem(InputSourceManager* inputManager);
	void Update(DX::StepTimer const& timer);
	InputButtons GetButtons();

private:
	InputSourceManager* m_inputManager;
	InputButtons m_currentButtons;

};

