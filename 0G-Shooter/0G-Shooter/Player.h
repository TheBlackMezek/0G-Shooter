#pragma once


//union vec2;
#include "MathLib\Vec2.h"
class Mat3;

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



	void applyInput();
	void update();
	void draw();
	void drawMatrix();

	Mat3 getLocalTransform();

private:
	float centerX;
	float centerY;
};

