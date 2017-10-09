#include "Player.h"

#include "sfwdraw.h"



Player::Player()
{
	x = 0;
	y = 0;
	speed = 2;
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
}

void Player::draw()
{
	sfw::drawCircle(x, y, 20);
}
