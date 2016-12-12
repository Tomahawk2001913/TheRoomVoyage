#pragma once

#include <TE2D/SimpleApplication.h>
#include <TE2D/graphics/Renderer.h>
#include <TE2D/graphics/Camera.h>
#include "GameStateManager.h"

class Game : public tom::SimpleApplication {
public:
	Game();
	~Game();

	void render();
	void update(float delta);
private:
	tom::graphics::Renderer* renderer;
	tom::graphics::Camera* camera;
	GameStateManager* gsm;
};

