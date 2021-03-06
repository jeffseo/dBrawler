#pragma once
#include <SDL.h>

//The dot that will move around on the screen
class Dot
{
public:
	//The dimensions of the dot
	static const int DEFAULT_DOT_WIDTH = 10;
	static const int DEFAULT_DOT_HEIGHT = 10;

	//Maximum axis velocity of the dot
	static const int DEFAULT_DOT_VEL = 5;

	//Initializes the variables
	Dot(const uint32_t screenWidth, const uint32_t screenHeight);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Shows the dot on the screen
	void render(SDL_Renderer& mpRenderer);
	
	bool IsEaten() const;

private:
	//The X and Y offsets of the dot
	int mPosX;
	int mPosY;
	int mHeight;
	int mWidth;

	int mScreenWidth;
	int mScreenHeight;

	bool mEaten;
};