#pragma once

#include <TE2D/graphics/Renderer.h>

class GameStateManager;

class GameState {
public:
	GameState(GameStateManager* game);
	virtual ~GameState();

	virtual void render(tom::graphics::Renderer* renderer) = 0;
	virtual void update(float delta) = 0;

	virtual void changedTo(GameState* oldGameState) {};
	virtual void changedFrom(GameState* newGameState) {};
private:
	GameStateManager* gameStateManager = NULL;
};