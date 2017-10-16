#include "Player.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"



Player::Player()
{
	collider.pos.x = 0;
	collider.pos.y = 0;
	accel = 5;

	rotation = 0;
	rotAccel = 0.04;

	centerX = 800 / 2;
	centerY = 600 / 2;

	facing.x = 0;
	facing.y = 0;

	collider.canMove = true;
	collider.radius = 20;
}


Player::~Player()
{
}


void Player::update()
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
