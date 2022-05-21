#pragma once
#include"Object.h"

using namespace TA;
class Half :public Object
{
private:
	int index;
	bool isTop;
public:
	Half();
	~Half();
	void init(SDL_Renderer* renderer, int index, bool top);
	void move();
	void reset();
	bool isPass();
};

