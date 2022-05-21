#include "Bird.h"

using namespace TA;

Bird::Bird(SDL_Renderer* renderer)
{
	x_p = 0;
	y_p = 0;
	rect.x = SCREEN_WIDTH / 10;
	rect.y = SCREEN_HEIGHT /4;
	rect.w = 50;
	rect.h = 40;
	body = loadTexture(renderer, "bird.png");
}

Bird::~Bird()
{
}

void Bird::move_p(SDL_Renderer* renderer, SDL_Event event, Mix_Chunk* bulletSound)
{
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			y_p = -rect.h / 4;
			break;
		case SDLK_SPACE:
		{
			y_p = -rect.h / 4;
			break;
		}
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			y_p = 0;
			break;
		case SDLK_SPACE:
			y_p = 0;
			break;
		default:
			break;
		}
	}
}

void Bird::move()
{
	rect.y += 4;
	rect.y += y_p;

	if (rect.y < 0 || rect.y + rect.h > SCREEN_HEIGHT - 100) {
		rect.y -= 4;
		rect.y -= y_p;
	}

}
SDL_Rect Bird::p_rect() {
	SDL_Rect r;
	r.x = rect.x + rect.w / 6;
	r.y = rect.y + rect.h / 3;
	r.w = rect.w * 2 / 3;
	r.h = rect.h * 2 / 3;
	return r;
}
