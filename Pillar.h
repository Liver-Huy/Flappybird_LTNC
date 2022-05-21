#pragma once
#include"Object.h"
#include"Half.h"

using namespace TA;

class Pillar :public Object
{
private:
	Half top;
	Half bottom;
	int index;
public:
	Pillar();
	~Pillar();
	void init(SDL_Renderer* renderer, int index);
	void move();
	void show(SDL_Renderer* renderer);
	bool colli(SDL_Rect bird);
	bool isPass() { return top.isPass(); }
};

