#include "Entity.h"

#include "Bullet.h"
#include "PlayingGameState.h"

Entity::Entity(PlayingGameState* playingGameState) {
	this->playingGameState = playingGameState;
}

Entity::~Entity() {

}

void Entity::updatePosition(float delta, int size) {
	velX += aclX * delta;
	velY += aclY * delta;

	x += velX * delta;
	y += velY * delta;

	if(x < 0) x = 0;
	else if(x > 1280 - size) x = 1280 - size;

	bounds.x = x;
	bounds.y = y;
	bounds.w = size;
	bounds.h = size;

	if(velY > 0) bounds.y -= size;
}

void Entity::shoot(bool down) {
	Bullet* bullet = new Bullet(playingGameState);

	if(down) bullet->y = y;
	else bullet->y = y;

	bullet->x = x + ENTITY_SIZE / 2;

	bullet->velY = -300;
	if(down) { bullet->velY *= -1; bullet->hostile = true; }

	playingGameState->addEntity(bullet);
}