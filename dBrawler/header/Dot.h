#pragma once
#include <SDL.h>
#include "LTexture.h"

enum class Direction_e
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	INVALID_DIRECTION
};

//The dot that will move around on the screen
class Dot
{
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
	Dot(LTexture& gDotTexture, const uint32_t screenWidth, const uint32_t screenHeight);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot
	void move();

	//Shows the dot on the screen
	void render(SDL_Renderer& mpRenderer);

private:
	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelocity;

	Direction_e mDirection;

	int mScreenWidth;
	int mScreenHeight;
	LTexture& mpDotTexture;
};