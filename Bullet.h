#pragma once

#include "Entity.h"

#define BULLET_SIZE 16

class Bullet : public Entity {
public:
	Bullet(PlayingGameState* playingGameState);
	virtual ~Bullet();

	void render(tom::graphics::Renderer* renderer);
	void update(float delta);
};

