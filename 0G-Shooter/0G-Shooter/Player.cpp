#include "Player.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"
#include "MathLib\Mat3.h"



Player::Player()
{
	collider.pos.x = 0;
	collider.pos.y = 0;
	accel = 5;

	rotation = 0;
	rotAccel = 0.04;

	centerX = 800 / 2;
	centerY = 600 / 2;

	facing.x = cos(rotation);
	facing.y = sin(rotation);

	collider.canMove = true;
	collider.radius = 20;
}


Player::~Player()
{
}



void Player::applyInput()
{
	if (sfw::getKey('Q'))
	{
		rotation += rotAccel;
		if (rotation > M_PI * 2)
		{
			rotation -= M_PI * 2;
		}
		facing.x = cos(rotation);
		facing.y = sin(rotation);
	}
	if (sfw::getKey('E'))
	{
		rotation -= rotAccel;
		if (rotation < 0)
		{
			rotation += M_PI * 2;
		}
		facing.x = cos(rotation);
		facing.y = sin(rotation);
	}



	if (sfw::getKey('W'))
	{
		//y += speed;
		collider.vel.x += facing.x * accel;
		collider.vel.y += facing.y * accel;
	}
	if (sfw::getKey('S'))
	{
		//y -= speed;
		collider.vel.x -= facing.x * accel;
		collider.vel.y -= facing.y * accel;
	}
	if (sfw::getKey('A'))
	{
		//x -= speed;
		vec2 perp = perpendicular(facing, false);
		collider.vel.x += perp.x * accel;
		collider.vel.y += perp.y * accel;
	}
	if (sfw::getKey('D'))
	{
		//x += speed;
		vec2 perp = perpendicular(facing, true);
		collider.vel.x += perp.x * accel;
		collider.vel.y += perp.y * accel;
	}
}

void Player::update()
{
	collider.update();
}

void Player::draw()
{
	//sfw::drawCircle(x, y, 20);
	sfw::drawCircle(centerX, centerY, 20);

	//sfw::drawLine(x, y, x + cos(rotation) * 30, y + sin(rotation) * 30);
	//sfw::drawLine(centerX, centerY, centerX + cos(rotation) * 30, centerY + sin(rotation) * 30);
	sfw::drawLine(centerX, centerY, centerX, centerY + 30);
}

void Player::drawMatrix()
{
	float drawScale = 2.0f;

	Mat3 m = getLocalTransform();
	//Mat3 m = translation(collider.pos);
	//Mat3 m = rotationByRad(rotation);
	//Mat3 m = scaleMat({ collider.radius * 2, collider.radius * 2 }) * rotationByRad(rotation) * translation(collider.pos);
	
	vec2 pos = { m[6], m[7] };
	vec2 right_ep = { pos.x + m[0] * drawScale, pos.y + m[1] * drawScale };
	vec2 up_ep = { pos.x + m[3] * drawScale, pos.y + m[4] * drawScale };

	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawScale);
}


Mat3 Player::getLocalTransform()
{
	/*return translation(collider.pos) * 
		scaleMat({ collider.radius * 2, collider.radius * 2 }) * 
			rotationByRad(rotation);*/
	return scaleMat({ collider.radius * 2, collider.radius * 2 }) *
		rotationByRad(rotation) *
		translation(collider.pos);
}
