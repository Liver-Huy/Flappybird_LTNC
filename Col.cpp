#include "Col.h"

Col::Col()
{
	rect.w = 50;
	rect.h = 50;
}

Col::~Col()
{
}

void Col::init(SDL_Renderer* renderer)
{
	rect.x = SCREEN_WIDTH;
	rect.y = 0;
	body = TA::loadTexture(renderer, "col.png");
}

void Col::move()
{
	rect.x -= 4;
	if (rect.x < 0) {
		rect.x = SCREEN_WIDTH;
	}
}
