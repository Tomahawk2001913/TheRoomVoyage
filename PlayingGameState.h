#pragma once

#include <vector>
#include "GameState.h"
#include "PlayingInput.h"
#include "Player.h"

class PlayingGameState : public GameState {
public:
	PlayingGameState(GameStateManager* gameStateManager);
	~PlayingGameState();

	void render(tom::graphics::Renderer* renderer);
	void update(float delta);

	std::vector<Entity*> getEntities();
	void addEntity(Entity* entity);
	void spawnEnemy(float x = 0.0f);
	int getEntityAmount();
private:
	Player* player;
	PlayingInput* input;
	std::vector<Entity*> entities;
};