#pragma once


//union vec2;
#include "MathLib\Vec2.h"


class Player
{
public:
	Player();
	~Player();

	float x;
	float y;
	float speed;

	float rotation;
	vec2 facing;
	float rotSpeed;

	void update();

	void draw();
private:
	float centerX;
	float centerY;
};

