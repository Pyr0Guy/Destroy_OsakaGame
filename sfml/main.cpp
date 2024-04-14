#include <iostream>

#include "engine/Window.h"

int main(int argc, char* argv[])
{
	srand(static_cast<unsigned>(time(NULL)));

	Game GameWindow;

	while (GameWindow.GameRunning())
	{
		GameWindow.Update();
		GameWindow.Render();
	}

	return EXIT_SUCCESS;
}