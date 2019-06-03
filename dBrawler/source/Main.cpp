#include "Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
	game.Start();
	return 0;
}