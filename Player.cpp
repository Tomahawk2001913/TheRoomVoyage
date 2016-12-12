#include "Player.h"

#include "Resources.h"

Player::Player(PlayingGameState* playingGameState) : Entity(playingGameState) {
	x = 500;
	y = 525;
}

Player::~Player() {

}

void Player::render(tom::graphics::Renderer* renderer) {
	renderer->render(Resources::playerTexture, x, y, ENTITY_SIZE, ENTITY_SIZE);
}

void Player::update(float delta) {
	velX = 0;
	velY = 0;

	if(left) velX -= ENTITY_SPEED;
	if(right) velX += ENTITY_SPEED;

	updatePosition(delta);
}

void Player::goLeft() {
	left = true;
}

void Player::goRight() {
	right = true;
}

void Player::stopGoingLeft() {
	left = false;
}

void Player::stopGoingRight() {
	right = false;
}