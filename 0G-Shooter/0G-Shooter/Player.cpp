#include "Player.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "sfwdraw.h"



Player::Player()
{
	x = 0;
	y = 0;
	speed = 2;

	rotation = 0;
	rotSpeed = 0.1;
}


Player::~Player()
{
}


void Player::update()
{
	if (sfw::getKey('W'))
	{
		y += speed;
	}
	if (sfw::getKey('S'))
	{
		y -= speed;
	}
	if (sfw::getKey('A'))
	{
		x -= speed;
	}
	if (sfw::getKey('D'))
	{
		x += speed;
	}

	if (sfw::getKey('Q'))
	{
		rotation += rotSpeed;
		if (rotation > M_PI * 2)
		{
			rotation -= M_PI * 2;
		}
	}
	if (sfw::getKey('E'))
	{
		rotation -= rotSpeed;
		if (rotation < 0)
		{
			rotation += M_PI * 2;
		}
	}
}

void Player::draw()
{
	sfw::drawCircle(x, y, 20);

	sfw::drawLine(x, y, x + cos(rotation) * 30, y + sin(rotation) * 30);
}
