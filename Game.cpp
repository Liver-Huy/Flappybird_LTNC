#include"Game.h"

void GAME::initMenu(SDL_Renderer* renderer, TTF_Font* fontText, Text& menu1, SDL_Texture*& menu)
{
	menu1.initText(fontText);
	menu1.setText("Start");
	menu1.setRect(SCREEN_WIDTH * 3 / 4, SCREEN_HEIGHT * 3 / 4);
	menu1.setSize(200, 100);

	menu = loadTexture(renderer, "menu.jpg");
}

void GAME::showMark(SDL_Renderer* renderer, TTF_Font* fontText, Text& mark, int mks)
{
	string s = "Score: ";
	s = s + to_string(mks);
	mark.setText(s);
	mark.creatText(fontText, renderer);
}

void GAME::initGame(SDL_Renderer* renderer, SDL_Rect& bg, SDL_Rect& bgz, Mix_Chunk*& bum,
	Mix_Music*& brokenPlane, SDL_Texture*& tx1, SDL_Texture*& tx2)
{
	bg.x = SCREEN_WIDTH;
	bg.y = 0;
	bg.w = SCREEN_WIDTH;
	bg.h = SCREEN_HEIGHT;

	bgz.x = 0;
	bgz.y = 0;
	bgz.w = SCREEN_WIDTH;
	bgz.h = SCREEN_HEIGHT;

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
		cout << "-1";
	}
	music = Mix_LoadMUS("mbg.mp3");
	;	if (music == NULL)
	{
		cout << Mix_GetError();
	}
	brokenPlane = Mix_LoadMUS("broken.mp3");
	bum = Mix_LoadWAV("bum.wav");

	Mix_PlayMusic(music, 10);

	tx1 = loadTexture(renderer, "bg1.png");
	tx2 = loadTexture(renderer, "bg1.png");
}

void GAME::ResetGame(bool& quit, int& mk)
{
	quit = false;
	mk = 0;
}

void GAME::instruction(SDL_Renderer* renderer, int x)
{
	SDL_Texture* bgr = loadTexture(renderer, "bg1.png");
	SDL_RenderCopy(renderer, bgr, NULL, NULL);
	Text ins1;
	ins1.initText(fontText);
	ins1.setText("Press SPACE to fly");
	ins1.setSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10);
	ins1.setRect(SCREEN_WIDTH / 2 - ins1.getRect().w / 2, SCREEN_HEIGHT * 2 / 6);

	ins1.creatText(fontText, renderer);


	SDL_RenderPresent(renderer);
	SDL_Event e;
	while (true) {
		if (SDL_WaitEvent(&e) != 0 &&
			(e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
			return;
		SDL_Delay(100);
	}
}

void GAME::loadMap(SDL_Renderer* renderer, SDL_Rect& bg,
	SDL_Rect& bgz, SDL_Texture* tx1, SDL_Texture* tx2)
{
	bg.x -= 2;
	bgz.x -= 2;
	SDL_RenderCopy(renderer, tx1, NULL, &bg);
	SDL_RenderCopy(renderer, tx2, NULL, &bgz);
	if (bg.x + SCREEN_WIDTH < 0) {
		bg.x = SCREEN_WIDTH;
	}
	if (bgz.x + SCREEN_WIDTH < 0) {
		bgz.x = SCREEN_WIDTH;
	}
}
void GAME::RunPE(SDL_Renderer* renderer, Bird& player, vector<Pillar>& cols, bool& quit, int& mk)
{
	for (int ie = 0; ie < cols.size(); ie++) {
		cols.at(ie).move();
		cols.at(ie).show(renderer);
		if (cols.at(ie).isPass())
			mk++;
		if (cols.at(ie).colli(player.p_rect())) {
			Mix_PlayMusic(brokenPlane, 0);
			quitGame(quit);
			cout << "col" << endl;
		}
	}

	//Render Player
	player.show(renderer);
	player.move();
}

void GAME::showLastScore(SDL_Renderer* renderer, SDL_Texture*& endGame, TTF_Font* fontText, int mks)
{
	Text score, playAgain;
	endGame = TA::loadTexture(renderer, "gameover.jpg");
	score.initText(fontText);
	score.setText("Your Score: " + to_string(mks));
	score.setSize(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 70 * 8);
	score.setRect(SCREEN_WIDTH / 2 - score.getRect().w / 2, 5);
	playAgain.initText(fontText);
	playAgain.setText("Press BACKSPACE to exit or any key to play again !");
	playAgain.setSize(SCREEN_WIDTH * 9 / 10, SCREEN_HEIGHT / 10);
	playAgain.setRect(SCREEN_WIDTH / 2 - playAgain.getRect().w / 2, SCREEN_HEIGHT - 75);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, endGame, NULL, NULL);
	score.creatText(fontText, renderer);
	playAgain.creatText(fontText, renderer);
	SDL_RenderPresent(renderer);
	//SDL_Delay(5000);
}

void GAME::quitGame(bool& quit)
{
	SDL_Delay(100);
	if (MessageBox(NULL, L"Game Over!", L"Oh! Noo . . .", MB_OK)) {
		quit = true;
	}
}
