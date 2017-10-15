#include "Circle.h"


#define _USE_MATH_DEFINES
#include <cmath>

#include "sfwdraw.h"


Circle::Circle()
{
	pos.x = 0;
	pos.y = 0;
	radius = 10;
}


Circle::~Circle()
{
}




void Circle::draw(vec2 playerPos, vec2 playerFacing)
{
	vec2 offset;
	offset.x = playerPos.x - pos.x;
	offset.y = playerPos.y - pos.y;
	float dist = magnitude(offset);

	float ang = angle(playerFacing, offset);
	if (isAngleClockwise(playerFacing, offset))
	{
		ang *= -1;
	}

	ang += M_PI;
	
	sfw::drawCircle(400 + sin(ang) * dist,
					300 + cos(ang) * dist,
					radius);
}

void Circle::draw(vec2 playerPos, vec2 playerFacing, vec2 pos, float radius)
{
	vec2 offset;
	offset.x = playerPos.x - pos.x;
	offset.y = playerPos.y - pos.y;
	float dist = magnitude(offset);

	float ang = angle(playerFacing, offset);
	if (isAngleClockwise(playerFacing, offset))
	{
		ang *= -1;
	}

	ang += M_PI;

	sfw::drawCircle(400 + sin(ang) * dist,
		300 + cos(ang) * dist,
		radius);
}
