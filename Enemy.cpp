#include "Enemy.h"

#include "Resources.h"

Enemy::Enemy(PlayingGameState* playingGameState) : Entity(playingGameState) {
	hostile = true;
}

Enemy::~Enemy() {

}

void Enemy::render(tom::graphics::Renderer* renderer) {
	renderer->render(Resources::enemyTexture, x, y, ENTITY_SIZE, -ENTITY_SIZE);
}

void Enemy::update(float delta) {
	time += delta;

	if(time >= 1.5f) { time -= 1.5f; shoot(true); }

	updatePosition(delta);
}