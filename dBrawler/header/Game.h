#pragma once
#include "LTexture.h"
#include <memory>

class Game
{
public:
	Game(const int screenWidth, const int screenHeight);
	~Game();

	std::shared_ptr<SDL_Window> CreateWindow() const;
	std::shared_ptr<SDL_Renderer> CreateRenderer(std::shared_ptr<SDL_Window> pWindow) const;
	
	//Starts up SDL and creates window
	bool Init();

	//Frees media and shuts down SDL
	void Close();

	//Loads media
	bool LoadMedia();

private:
	//The window we'll be rendering to
	std::shared_ptr<SDL_Window> mpWindow;

	//The window renderer
	std::shared_ptr<SDL_Renderer> mpRenderer;

	//Scene textures
	LTexture mDotTexture;
	LTexture mBGTexture;

	int mScreenWidth;
	int mScreenHeight;
};