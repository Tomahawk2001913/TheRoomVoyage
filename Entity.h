#pragma once

#include <TE2D/graphics/Renderer.h>
#include <SDL2/SDL.h>

#define ENTITY_SIZE 160
#define ENTITY_SPEED 650

class PlayingGameState;

class Entity {
public:
	Entity(PlayingGameState* playingGameState);
	virtual ~Entity();

	virtual void render(tom::graphics::Renderer* renderer) = 0;
	virtual void update(float delta) = 0;

	virtual void updatePosition(float delta, int size = ENTITY_SIZE);

	virtual void shoot(bool down = false);

	bool dead = false, hostile = false;

	float x = 0.0f, y = 0.0f, velX = 0.0f, velY = 0.0f, aclX = 0.0f, aclY = 0.0f;
	SDL_Rect bounds;
protected:
	PlayingGameState* playingGameState;
};

