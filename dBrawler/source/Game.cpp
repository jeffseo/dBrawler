//Using SDL, SDL_image, standard IO, vectors, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Game.h"
#include "Snake.h"
#include "Dot.h"

Game::Game(const int screenWidth, const int screenHeight)
	: mScreenWidth(screenWidth)
	, mScreenHeight(screenHeight)
	, mpWindow(nullptr)
	, mpRenderer(nullptr)
{
	SDL_assert(Init());
	SDL_assert(LoadMedia());
}

Game::~Game()
{
	//Free resources and close SDL
	Close();
}

std::unique_ptr<SDL_Window, SDL_Helper::SDL_Deleter> Game::CreateWindow() const
{
	SDL_Window* pWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
	if (pWindow == nullptr)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_assert(pWindow != nullptr);
	}
	return std::unique_ptr<SDL_Window, SDL_Helper::SDL_Deleter>(pWindow, SDL_Helper::SDL_Deleter());
}

std::unique_ptr<SDL_Renderer, SDL_Helper::SDL_Deleter> Game::CreateRenderer(std::unique_ptr<SDL_Window, SDL_Helper::SDL_Deleter>& pWindow) const
{
	//Create vsynced renderer for window
	SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (pRenderer == nullptr)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_assert(pRenderer != nullptr);
	}

	//Initialize renderer color
	SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		SDL_assert(true);
	}

	return std::unique_ptr<SDL_Renderer, SDL_Helper::SDL_Deleter>(pRenderer, SDL_Helper::SDL_Deleter());
}

bool Game::Init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		mpWindow = CreateWindow();
		mpRenderer = CreateRenderer(mpWindow);
	}

	return success;
}

void Game::Start()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//The dot that will be moving around on the screen
	//Dot snake(mDotTexture, mScreenWidth, mScreenHeight);
	Snake snake(0, 0, mScreenWidth, mScreenHeight);
	Dot food(mScreenWidth, mScreenHeight);

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			//Handle input for the dot
			snake.handleEvent(e);
		}

		Evaluate();
		//Move the dot
		snake.move();

		//Clear screen
		SDL_SetRenderDrawColor(mpRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mpRenderer.get());

		//Render background
		//mBGTexture.render(*mpRenderer, 0, 0);

		//Render objects
		snake.render(mpRenderer);

		//Update screen
		SDL_RenderPresent(mpRenderer.get());
	}
}

void Game::Close()
{
	//Free loaded images
	//mDotTexture.free();
	//mBGTexture.free();

	mpWindow.reset();
	mpRenderer.reset();

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool Game::LoadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	//if (!mDotTexture.loadFromFile("31_scrolling_backgrounds/dot.bmp", *mpRenderer))
	//{
	//	printf("Failed to load dot texture!\n");
	//	success = false;
	//}

	////Load background texture
	//if (!mBGTexture.loadFromFile("31_scrolling_backgrounds/bg.png", *mpRenderer))
	//{
	//	printf("Failed to load background texture!\n");
	//	success = false;
	//}

	return success;
}

void Game::Evaluate()
{

}