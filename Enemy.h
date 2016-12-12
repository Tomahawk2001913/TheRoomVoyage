#pragma once

#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy(PlayingGameState* playingGameState);
	virtual ~Enemy();

	void render(tom::graphics::Renderer* renderer);
	void update(float delta);
private:
	float time = 0.0f;
};

