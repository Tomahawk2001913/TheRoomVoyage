#include "PlayingInput.h"

PlayingInput::PlayingInput(Player* player) {
	this->player = player;
}

PlayingInput::~PlayingInput() {

}

void PlayingInput::keyPressed(SDL_Keycode keyCode) {
	if(keyCode == SDLK_a || keyCode == SDLK_LEFT) player->goLeft();
	else if(keyCode == SDLK_d || keyCode == SDLK_RIGHT) player->goRight();
	else if(keyCode == SDLK_SPACE) player->shoot();
}

void PlayingInput::keyReleased(SDL_Keycode keyCode) {
	if (keyCode == SDLK_a || keyCode == SDLK_LEFT) player->stopGoingLeft();
	else if(keyCode == SDLK_d || keyCode == SDLK_RIGHT) player->stopGoingRight();
}