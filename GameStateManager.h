#pragma once

#include <TE2D/io/InputInterface.h>
#include "PlayingGameState.h"

class Game;
class GameState;

class GameStateManager {
public:
	GameStateManager(Game* game);
	~GameStateManager();

	GameState* getCurrentGameState();
	void changeGameState(GameState* gameState);

	void setInputInterface(tom::io::InputInterface* interface);

	PlayingGameState* playingGameState = NULL;
private:
	Game* game = NULL;
	GameState* currentGameState = NULL;
};