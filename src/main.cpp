#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {

    Game game;

	//Game loop
	while (game.running() && !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
	}
    return 0;
}

