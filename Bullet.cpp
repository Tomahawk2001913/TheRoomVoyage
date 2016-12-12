#include "Bullet.h"

#include "Resources.h"
#include "PlayingGameState.h"

Bullet::Bullet(PlayingGameState* playingGameState) : Entity(playingGameState) {

}

Bullet::~Bullet() {

}

void Bullet::render(tom::graphics::Renderer* renderer) {
	if(velY < 0) renderer->render(Resources::bulletTexture, x, y, BULLET_SIZE, BULLET_SIZE);
	else renderer->render(Resources::bulletTexture, x, y, BULLET_SIZE, -BULLET_SIZE);

}

void Bullet::update(float delta) {
	updatePosition(delta, BULLET_SIZE);

	std::vector<Entity*>& entities = playingGameState->getEntities();
	
	for (int i = 0; i < playingGameState->getEntityAmount(); ++i) {
		if(entities[i] == this) continue;
		if (SDL_HasIntersection(&bounds, &(entities[i]->bounds)) == SDL_TRUE && !entities[i]->dead && !(entities[i]->hostile && hostile)) {
			entities[i]->dead = true;
			dead = true;
		}
	}
}