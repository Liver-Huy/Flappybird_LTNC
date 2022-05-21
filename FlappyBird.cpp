#include"Game.h"
#include "Pillar.h"

using namespace GAME;

int main(int argc, char* argv[]) {

LOOP:
	srand(time(0));

	//Init SDL- LoadObject

	initSDL(window, renderer);

	initGame(renderer, bg, bgz, bum, brokenPlane, tx1, tx2);
	//initMenu(renderer, fontText, menu1, menu);
	mark.initText(fontText);

	//Creat Player
	Bird player(renderer);

	//Creat Enermy
	vector<Pillar> cols(5);
	for (int i = 0; i < cols.size(); i++) {
		cols.at(i).init(renderer, i);
	}

	ResetGame(quit, mk); //khởi tạo giá trị cho biến

	instruction(renderer, 1); //đưa ra màn hình giới thiệu

	//RunGame
	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			player.move_p(renderer, event, gunSound); // kiểm tra sự kiện bàn phím để xử lí player
		}

		SDL_RenderClear(renderer); // xóa hết màn hình

		loadMap(renderer, bg, bgz, tx1, tx2); // vẽ map

		RunPE(renderer, player, cols, quit, mk); // vẽ chim và cột

		showMark(renderer, fontText, mark, mk); // hiển thị điểm

		SDL_RenderPresent(renderer); // hiển thị tất cả ra màn hình 
	}

	showLastScore(renderer, endGame, fontText, mk);  // hiển thị điểm cuối 

	//Play Again or exit
	while (true)
	{
		if (SDL_WaitEvent(&event) && event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_BACKSPACE)
				break;
			else goto LOOP;
		}
	}

	return 0;
}