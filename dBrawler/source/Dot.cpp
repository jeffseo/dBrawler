#include "Dot.h"

Dot::Dot(LTexture& gDotTexture, const uint32_t screenWidth, const uint32_t screenHeight)
	: mpDotTexture(gDotTexture)
	, mDirection(Direction_e::INVALID_DIRECTION)
{
	//Initialize the offsets
	mPosX = 0;
	mPosY = 0;

	//Initialize the velocity
	mVelocity = 5;

	mScreenHeight = screenHeight;
	mScreenWidth = screenWidth;
}

void Dot::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mDirection = Direction_e::NORTH; break;
		case SDLK_DOWN: mDirection = Direction_e::SOUTH; break;
		case SDLK_LEFT: mDirection = Direction_e::WEST; break;
		case SDLK_RIGHT: mDirection = Direction_e::EAST; break;
		}
	}
}

void Dot::move()
{
	switch (mDirection)
	{
		case Direction_e::NORTH:
			mPosY -= mVelocity;
			break;
		case Direction_e::SOUTH:
			mPosY += mVelocity;
			break;
		case Direction_e::EAST:
			mPosX += mVelocity;
			break;
		case Direction_e::WEST:
			mPosX -= mVelocity;
			break;
		default:
			break;
	}

	//If the dot went too far to the left or right
	if (mPosX < 0)
	{
		mPosX = 0;
	}
	else if ((mPosX + DOT_WIDTH) > mScreenWidth)
	{
		mPosX = mScreenWidth - DOT_WIDTH;
	}

	//If the dot went too far up or down
	if (mPosY < 0)
	{
		mPosY = 0;
	}
	else if ((mPosY + DOT_HEIGHT) > mScreenHeight)
	{
		mPosY = mScreenHeight - DOT_HEIGHT;
	}
}

void Dot::render(SDL_Renderer& mpRenderer)
{
	//Show the dot
	mpDotTexture.render(mpRenderer, mPosX, mPosY);
}
