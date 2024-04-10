#include <iostream>

#include "engine/Window.h"

#if !NDEBUG
int main(int argc, char* argv[])
#else
int WinMain(int argc, char* argv[])
#endif
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