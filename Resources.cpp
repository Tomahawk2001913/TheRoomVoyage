#include "Resources.h"

tom::graphics::Texture* Resources::playerTexture = NULL;
tom::graphics::Texture* Resources::enemyTexture = NULL;
tom::graphics::Texture* Resources::bulletTexture = NULL;

Resources::Resources() {

}

Resources::~Resources() {

}

void Resources::initialize() {
	playerTexture = new tom::graphics::Texture(std::string("assets/textures/player.png"));
	enemyTexture = new tom::graphics::Texture(std::string("assets/textures/enemy.png"));
	bulletTexture = new tom::graphics::Texture(std::string("assets/textures/bullet.png"));
}

void Resources::close() {
	delete playerTexture;
	playerTexture = 0;
}