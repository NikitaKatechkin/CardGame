#include <iostream>

#include "Game.h"

int main()
{
	Game game;
	while (!game.GetWindow()->IsDone())
	{
		game.Update();
		game.Render();
		game.LateUpdate();
	}

	system("pause");

	return 0;
}