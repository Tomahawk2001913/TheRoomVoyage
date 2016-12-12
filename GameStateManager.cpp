#include "GameStateManager.h"

#include "Game.h"
#include "GameState.h"

GameStateManager::GameStateManager(Game* game) {
	this->game = game;
	playingGameState = new PlayingGameState(this);

	currentGameState = playingGameState;
}

GameStateManager::~GameStateManager() {
	delete playingGameState;
}

GameState* GameStateManager::getCurrentGameState() {
	return currentGameState;
}

void GameStateManager::changeGameState(GameState* gameState) {
	if(currentGameState != NULL) currentGameState->changedFrom(gameState);
	gameState->changedTo(currentGameState);
	currentGameState = gameState;
}

void GameStateManager::setInputInterface(tom::io::InputInterface* inputInterface) {
	game->setInputInterface(inputInterface);
}