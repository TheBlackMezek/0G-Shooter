#pragma once


//union vec2;
#include "MathLib\Vec2.h"

#include "CircleCollider.h"


class Player
{
public:
	Player();
	~Player();

	float accel;

	float rotation;
	vec2 facing;
	float rotAccel;

	CircleCollider collider;



	void update();
	void draw();

private:
	float centerX;
	float centerY;
};

