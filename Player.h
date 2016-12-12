#pragma once

#include "Entity.h"

class Player : public Entity {
public:
	Player(PlayingGameState* playingGameState);
	~Player();

	virtual void render(tom::graphics::Renderer* renderer);
	virtual void update(float delta);

	void goLeft();
	void goRight();

	void stopGoingLeft();
	void stopGoingRight();
private:
	bool left = false, right = false;
};