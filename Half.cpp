#include "Half.h"
#include"Game.h"

Half::Half()
{
	rect.w = 50;
}

Half::~Half()
{
}

void Half::init(SDL_Renderer* renderer, int index, bool top)
{
	this->index = index;
	this->isTop = top;
	rect.y = 0;
	rect.x = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 5 * index;
	rect.h = (rand() % SCREEN_HEIGHT) / 2;

	if (!top) {
		rect.y = SCREEN_HEIGHT - rect.h - SCREEN_HEIGHT/6 + 2;
	}
	if (top) {
		body = TA::loadTexture(renderer, "colTop.png");
	}
	else {
		body = TA::loadTexture(renderer, "colBottom.png");
	}
}

void Half::reset() {
	rect.x = SCREEN_WIDTH;
	rect.h = (rand() % SCREEN_HEIGHT) / 5 + SCREEN_HEIGHT/6;
	if (!isTop) {
		rect.y = SCREEN_HEIGHT - rect.h - SCREEN_HEIGHT / 6 + 2;
	}
}

void Half::move() {
	rect.x -= 2;
	if (rect.x + rect.w < 0) {
		reset();
	}
}

bool Half::isPass() {
	return abs(rect.x - SCREEN_WIDTH / 10) <= 1;
}