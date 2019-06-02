#pragma once
#include "LTexture.h"

class Game
{
	Game(const int screenWidth, const int screenHeight);
	~Game();

	//Starts up SDL and creates window
	bool Init();

	//Frees media and shuts down SDL
	void Close();

	//Loads media
	bool LoadMedia();

private:
	//The window we'll be rendering to
	SDL_Window * gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	//Scene textures
	LTexture gDotTexture;
	LTexture gBGTexture;

	int mScreenWidth;
	int mScreenHeight;
};