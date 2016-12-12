#pragma once

#include <TE2D/graphics/Texture.h>

class Resources {
public:
	Resources();
	~Resources();

	static void initialize();
	static void close();

	static tom::graphics::Texture *playerTexture, *enemyTexture, *bulletTexture;
};