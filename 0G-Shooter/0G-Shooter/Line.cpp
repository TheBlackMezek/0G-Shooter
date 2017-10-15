#include "Line.h"



#define _USE_MATH_DEFINES
#include <cmath>

#include "sfwdraw.h"


Line::Line()
{
	start.x = 0;
	start.y = 0;
	end.x = 0;
	end.y = 0;
}


Line::~Line()
{
}



void Line::draw(vec2 playerPos, vec2 playerFacing)
{
	vec2 startOffset;
	startOffset.x = playerPos.x - start.x;
	startOffset.y = playerPos.y - start.y;
	float startMag = magnitude(startOffset);
	vec2 endOffset;
	endOffset.x = playerPos.x - end.x;
	endOffset.y = playerPos.y - end.y;
	float endMag = magnitude(endOffset);

	float startAng = angle(playerFacing, startOffset);
	if (isAngleClockwise(playerFacing, startOffset))
	{
		startAng *= -1;
	}
	float endAng = angle(playerFacing, endOffset);
	if (isAngleClockwise(playerFacing, endOffset))
	{
		endAng *= -1;
	}

	startAng += M_PI;
	endAng += M_PI;

	//sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
	sfw::drawLine(400 + sin(startAng) * startMag,
		300 + cos(startAng) * startMag,
		400 + sin(endAng) * endMag,
		300 + cos(endAng) * endMag);
}

void Line::draw(vec2 playerPos, vec2 playerFacing, vec2 start, vec2 end)
{
	vec2 startOffset;
	startOffset.x = playerPos.x - start.x;
	startOffset.y = playerPos.y - start.y;
	float startMag = magnitude(startOffset);
	vec2 endOffset;
	endOffset.x = playerPos.x - end.x;
	endOffset.y = playerPos.y - end.y;
	float endMag = magnitude(endOffset);

	float startAng = angle(playerFacing, startOffset);
	if (isAngleClockwise(playerFacing, startOffset))
	{
		startAng *= -1;
	}
	float endAng = angle(playerFacing, endOffset);
	if (isAngleClockwise(playerFacing, endOffset))
	{
		endAng *= -1;
	}

	startAng += M_PI;
	endAng += M_PI;

	//sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
	sfw::drawLine(400 + sin(startAng) * startMag,
		300 + cos(startAng) * startMag,
		400 + sin(endAng) * endMag,
		300 + cos(endAng) * endMag);
}