#pragma once

#include <TE2D/io/InputInterface.h>
#include "Player.h"

class PlayingInput : public tom::io::InputInterface {
public:
	PlayingInput(Player* player);
	~PlayingInput();

	void keyPressed(SDL_Keycode keyCode);
	void keyReleased(SDL_Keycode keyCode);

	void mouseMoved(int x, int y, int dx, int dy) {};
private:
	Player* player = NULL;
};