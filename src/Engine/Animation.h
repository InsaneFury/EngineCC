#ifndef	ANIMATION_H
#define ANIMATION_H

#define EXPORTDLL _declspec(dllexport)

#include "glm/glm.hpp"

class EXPORTDLL Animation
{
private:
	float spritesheetWidth;
	float frameWidth;
	int maxRows;
	int actualRow;
	int framesCount;
	int actualFrame;
	float frameTime;
	glm::vec2 frameSizeProportion;
	float animationTime;
public:
	glm::vec2 frameCoords[4];
public:
	Animation(float _spritesheetWidth, float _frameWidth, int _rows);
	glm::vec2 GetCurrentFrameCoords(int index);
	void UpdateAnimation(float timer);
	void SetFrameCoords();
	void SelectAnimationByRow(int _frameCount, int _row, float _animationTime);
};

#endif