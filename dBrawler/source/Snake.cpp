#include "Snake.h"

//Initializes the variables
Snake::Snake(const int x, const int y, const uint32_t screenWidth, const uint32_t screenHeight)
	: mPosX(x)
	, mPosY(y)
	, mWidth(DEFAULT_DOT_WIDTH)
	, mHeight(DEFAULT_DOT_HEIGHT)
	, mVelocity(DEFAULT_DOT_VEL)
	, mDirection(Direction_e::INVALID_DIRECTION)
	, mScreenWidth(screenWidth)
	, mScreenHeight(screenHeight)
{

}

//Takes key presses and adjusts the dot's velocity
void Snake::handleEvent(SDL_Event& e)
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

//Moves the dot
void Snake::move()
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
	else if ((mPosX + mWidth) > mScreenWidth)
	{
		mPosX = mScreenWidth - mWidth;
	}

	//If the dot went too far up or down
	if (mPosY < 0)
	{
		mPosY = 0;
	}
	else if ((mPosY + mHeight) > mScreenHeight)
	{
		mPosY = mScreenHeight - mHeight;
	}
}

//Shows the dot on the screen
void Snake::render(const std::unique_ptr<SDL_Renderer, SDL_Helper::SDL_Deleter>& mpRenderer)
{
	//Show the dot
	const SDL_Renderer* pRenderer = mpRenderer.get();
	SDL_Rect fillRect = { mPosX, mPosY, mWidth, mHeight };
	SDL_SetRenderDrawColor(mpRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(mpRenderer.get(), &fillRect);
}