#pragma once
#include "LTexture.h"
#include "SDL_Helper.h"
#include <memory>

class Game
{
public:
	Game(const int screenWidth, const int screenHeight);
	~Game();

	std::unique_ptr<SDL_Window, SDL_Helper::SDL_Deleter> CreateWindow() const;
	std::unique_ptr<SDL_Renderer, SDL_Helper::SDL_Deleter> CreateRenderer(std::unique_ptr<SDL_Window, SDL_Helper::SDL_Deleter>& pWindow) const;
	
	//Starts up SDL and creates window
	bool Init();

	void Start();

	//Frees media and shuts down SDL
	void Close();

	//Loads media
	bool LoadMedia();

	void Evaluate();

private:
	//The window we'll be rendering to
	std::unique_ptr<SDL_Window, SDL_Helper::SDL_Deleter> mpWindow;

	//The window renderer
	std::unique_ptr<SDL_Renderer, SDL_Helper::SDL_Deleter> mpRenderer;

	int mScreenWidth;
	int mScreenHeight;
};