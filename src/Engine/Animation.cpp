#include "Animation.h"

Animation::Animation(float _spritesheetWidth, float _frameWidth, int _rows)
	:
	spritesheetWidth(_spritesheetWidth),
	frameWidth(_frameWidth),
	maxRows(_rows),
	actualFrame(0),
	actualRow(0),
	frameTime(0)
{
	frameSizeProportion.x = 1 / (spritesheetWidth / frameWidth);
	frameSizeProportion.y = 1 / (float)maxRows;
	SetFrameCoords();
}

void Animation::UpdateAnimation(float timer)
{
	if (frameTime >= animationTime / framesCount)
	{
		frameTime = 0;
		actualFrame++;
		if (actualFrame >= framesCount)
			actualFrame = 0;
	}

	SetFrameCoords();

	frameTime += timer;
}

void Animation::SetFrameCoords()
{
	frameCoords[0] = { actualFrame * frameSizeProportion.x, (actualRow + 1) * frameSizeProportion.y }; //top left
	frameCoords[1] = { (actualFrame + 1) * frameSizeProportion.x, (actualRow + 1) * frameSizeProportion.y }; //top right
	frameCoords[2] = { actualFrame * frameSizeProportion.x, actualRow * frameSizeProportion.y }; //bottom left
	frameCoords[3] = { (actualFrame + 1) * frameSizeProportion.x, actualRow * frameSizeProportion.y }; //bottom right
}

glm::vec2 Animation::GetCurrentFrameCoords(int index)
{
	return frameCoords[index];
}

void Animation::SelectAnimationByRow(int _frameCount, int _row,float _animationTime)
{
	framesCount = _frameCount;
	animationTime = _animationTime;
	if (actualRow != _row)
	{
		actualFrame = 0;
		actualRow = _row;
		frameTime = 0;
	}
}