#include "Dot.h"

Dot::Dot(const uint32_t screenWidth, const uint32_t screenHeight)
	: mHeight(DEFAULT_DOT_HEIGHT)
	, mWidth(DEFAULT_DOT_WIDTH)
	, mEaten(false)
{
	//Initialize the offsets
	mPosX = 0;
	mPosY = 0;

	mScreenHeight = screenHeight;
	mScreenWidth = screenWidth;
}

void Dot::handleEvent(SDL_Event& e)
{

}

void Dot::render(SDL_Renderer& mpRenderer)
{
	//Show the dot
	SDL_Rect fillRect = { mPosX, mPosY, mWidth, mHeight };
	SDL_SetRenderDrawColor(&mpRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(&mpRenderer, &fillRect);
	//mpDotTexture.render(mpRenderer, mPosX, mPosY);
}

bool Dot::IsEaten() const
{
	return mEaten;
}

