#pragma once
#include"ta.h"
#include"Object.h"

using namespace TA;

class Bird : public Object
{
private:
	int x_p;
	int y_p;

public:
	Bird(SDL_Renderer* renderer);
	~Bird();

	void move_p(SDL_Renderer* renderer, SDL_Event event, Mix_Chunk* bulletSound);
	void move();

	SDL_Rect p_rect();

};

