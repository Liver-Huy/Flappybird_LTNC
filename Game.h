#ifndef GAME_H_
#define GAME_H_

#include "ta.h"
#include"Object.h"
#include"Bird.h"
#include"Pillar.h"
#include"Text.h"

static Text menu1;
static Text mark;
static int mk = 0;
static SDL_Texture* menu = NULL;
static SDL_Texture* endGame;
static SDL_Texture* tx1;
static SDL_Texture* tx2;

using namespace TA;

namespace GAME
{
	void initMenu(SDL_Renderer* renderer, TTF_Font* fontText, Text& menu1, SDL_Texture*& menu);

	void showMark(SDL_Renderer* renderer, TTF_Font* fontText, Text& mark, int mks);

	void initGame(SDL_Renderer* renderer, SDL_Rect& bg, SDL_Rect& bgz, Mix_Chunk*& bum,
		Mix_Music*& brokenPlane, SDL_Texture*& tx1, SDL_Texture*& tx2);

	void ResetGame(bool& quit, int& mk);

	void instruction(SDL_Renderer* renderer, int x);

	void loadMap(SDL_Renderer* renderer, SDL_Rect& bg,
		SDL_Rect& bgz, SDL_Texture* tx1, SDL_Texture* tx2);

	void showLastScore(SDL_Renderer* renderer, SDL_Texture*& endGame, TTF_Font* fontText, int mks);

	void RunPE(SDL_Renderer* renderer, Bird& player, vector<Pillar>& cols, bool& quit, int& mk);

	void quitGame(bool& quit);
}
#endif 
