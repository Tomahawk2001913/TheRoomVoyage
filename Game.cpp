#include "Game.h"

#include <string>
#include <GLEW/GL/glew.h>
#include <TE2D/graphics/Camera.h>
#include "GameState.h"
#include "Resources.h"

Game::Game() : tom::SimpleApplication(std::string("The Room Voyage - A Pathetic Ludum Dare 37 Submission by Tomahawk2001913")) {
	renderer = new tom::graphics::Renderer(std::string("assets/shaders/vertex.glsl"), std::string("assets/shaders/fragment.glsl"));
	gsm = new GameStateManager(this);
	camera = new tom::graphics::Camera(window->getWidth(), window->getHeight());

	renderer->begin();
	renderer->setProjectionMatrix(camera->getProjectionMatrix());
	renderer->end();

	Resources::initialize();
}

Game::~Game() {
	delete camera;
	delete renderer;

	Resources::close();
}

void Game::render() {
	// The "engine" already clears the color, but it is locked in on red...
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	renderer->begin();
	gsm->getCurrentGameState()->render(renderer);
	renderer->end();
}

void Game::update(float delta) {
	gsm->getCurrentGameState()->update(delta);
}