#include "Pillar.h"

Pillar::Pillar()
{
}

Pillar::~Pillar()
{
}

void Pillar::init(SDL_Renderer* renderer, int index)
{
	this->index = index;
	top.init(renderer, index, true);
	bottom.init(renderer, index, false);
}

void Pillar::move()
{
	top.move();
	bottom.move();
}

void Pillar::show(SDL_Renderer* renderer) {
	top.show(renderer);
	bottom.show(renderer);
}

bool Pillar::colli(SDL_Rect bird)
{
	return checkCollision(bird, top.getRect()) || checkCollision(bird, bottom.getRect());
}
