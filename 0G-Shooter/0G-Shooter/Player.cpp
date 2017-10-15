#include "Player.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"



Player::Player()
{
	x = 0;
	y = 0;
	speed = 2;

	rotation = 0;
	rotSpeed = 0.04;

	centerX = 800 / 2;
	centerY = 600 / 2;

	facing.x = 0;
	facing.y = 0;
}


Player::~Player()
{
}


void Player::update()
{
	if (sfw::getKey('W'))
	{
		//y += speed;
		x += facing.x * speed;
		y += facing.y * speed;
	}
	if (sfw::getKey('S'))
	{
		//y -= speed;
		x -= facing.x * speed;
		y -= facing.y * speed;
	}
	if (sfw::getKey('A'))
	{
		//x -= speed;
		vec2 perp = perpendicular(facing, false);
		x += perp.x * speed;
		y += perp.y * speed;
	}
	if (sfw::getKey('D'))
	{
		//x += speed;
		vec2 perp = perpendicular(facing, true);
		x += perp.x * speed;
		y += perp.y * speed;
	}

	if (sfw::getKey('Q'))
	{
		rotation += rotSpeed;
		if (rotation > M_PI * 2)
		{
			rotation -= M_PI * 2;
		}
		facing.x = cos(rotation);
		facing.y = sin(rotation);
	}
	if (sfw::getKey('E'))
	{
		rotation -= rotSpeed;
		if (rotation < 0)
		{
			rotation += M_PI * 2;
		}
		facing.x = cos(rotation);
		facing.y = sin(rotation);
	}
}

void Player::draw()
{
	//sfw::drawCircle(x, y, 20);
	sfw::drawCircle(centerX, centerY, 20);

	//sfw::drawLine(x, y, x + cos(rotation) * 30, y + sin(rotation) * 30);
	//sfw::drawLine(centerX, centerY, centerX + cos(rotation) * 30, centerY + sin(rotation) * 30);
	sfw::drawLine(centerX, centerY, centerX, centerY + 30);
}
