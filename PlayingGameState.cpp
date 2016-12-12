#include "PlayingGameState.h"

#include "GameStateManager.h"
#include "Enemy.h"

PlayingGameState::PlayingGameState(GameStateManager* gameStateManager) : GameState(gameStateManager) {
	player = new Player(this);
	input = new PlayingInput(player);
	gameStateManager->setInputInterface(input);

	spawnEnemy(500);
	spawnEnemy(250);
	spawnEnemy(750);
}

PlayingGameState::~PlayingGameState() {
	delete player;

	for (int i = 0; i < entities.size(); ++i) {
		delete entities[i];
	}
}

void PlayingGameState::render(tom::graphics::Renderer* renderer) {
	player->render(renderer);

	for (int i = 0; i < entities.size(); ++i) {
		if(!entities[i]->dead) entities[i]->render(renderer);
	}
}

void PlayingGameState::update(float delta) {
	player->update(delta);

	for (int i = 0; i < entities.size(); ++i) {
		if (!entities[i]->dead) entities[i]->update(delta);
	}
}

std::vector<Entity*> PlayingGameState::getEntities() {
	return entities;
}

void PlayingGameState::addEntity(Entity* entity) {
	entities.push_back(entity);
}

void PlayingGameState::spawnEnemy(float x) {
	Enemy* enemy = new Enemy(this);

	enemy->x = x;
	enemy->y = 0 - ENTITY_SIZE;
	enemy->velY = ENTITY_SPEED * 0.25f;

	addEntity(enemy);
}

int PlayingGameState::getEntityAmount() {
	return entities.size();
}