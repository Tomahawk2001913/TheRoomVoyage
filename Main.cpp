#include <iostream>

#include <TE2D/TomEngine2D.h>
#include "Game.h"
#include "Resources.h"

int main(int argc, char* argv[]) {
	std::cout << "Starting The Room Voyage." << std::endl;

	tom::initialize();

	Game game;
	game.start();

	tom::quit();

	std::cout << "Quiting The Room Voyage." << std::endl;

	return 0;
}