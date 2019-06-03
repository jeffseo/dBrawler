#pragma once
#include <SDL.h>
#include <memory>
#include "SDL_Helper.h"

enum class Direction_e
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	INVALID_DIRECTION
};

class Snake
{
public:
	//The dimensions of the dot
	static const int DEFAULT_DOT_WIDTH = 10;
	static const int DEFAULT_DOT_HEIGHT = 10;

	//Maximum axis velocity of the dot
	static const int DEFAULT_DOT_VEL = 5;

	//Initializes the variables
	Snake(const int x, const int y, const uint32_t screenWidth, const uint32_t screenHeight);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot
	void move();

	//Shows the dot on the screen
	void render(const std::unique_ptr<SDL_Renderer, SDL_Helper::SDL_Deleter>& mpRenderer);

private:
	//The X and Y offsets of the dot
	int mPosX;
	int mPosY;
	int mHeight;
	int mWidth;
	uint32_t mVelocity;
	Direction_e mDirection;

	int mScreenWidth;
	int mScreenHeight;
};