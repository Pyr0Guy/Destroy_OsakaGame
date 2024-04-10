#include <iostream>

#include "engine/Window.h"

int WinMain(int argc, char* argv[])
{
	srand(static_cast<unsigned>(time(NULL)));

	Game GameWindow;

	while (GameWindow.GetGameRunningState())
	{
		GameWindow.UpdateWindow();
		GameWindow.DrawWindow();
	}

	return EXIT_SUCCESS;
}