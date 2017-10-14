
#define _USE_MATH_DEFINES
#include <cmath>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"

#include "Player.h"



int main()
{
	
	sfw::initContext(800, 600, "0G Shooter");

	sfw::setBackgroundColor(BLACK);



	Player player;

	vec2 lineStart;
	lineStart.x = 100;
	lineStart.y = 110;
	vec2 lineEnd;
	lineEnd.x = 150;
	lineEnd.y = 120;

	

	while (sfw::stepContext())
	{
		
		player.update();
		vec2 ppos;
		ppos.x = player.x;
		ppos.y = player.y;

		player.draw();

		sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
		sfw::drawCircle(player.x, player.y, 20);

		vec2 renderFacing;
		renderFacing.x = 0;
		renderFacing.y = 1;
		float facingAng = angle(player.facing, renderFacing);
		if (isAngleClockwise(player.facing, renderFacing))
		{
			facingAng *= -1;
		}

		vec2 startOffset;
		startOffset.x = player.x - lineStart.x;
		startOffset.y = player.y - lineStart.y;
		float startMag = magnitude(startOffset);
		vec2 endOffset;
		endOffset.x = player.x - lineEnd.x;
		endOffset.y = player.y - lineEnd.y;
		float endMag = magnitude(endOffset);

		float startAng = angle(player.facing, startOffset);
		if (isAngleClockwise(player.facing, startOffset))
		{
			startAng *= -1;
		}
		float endAng = angle(player.facing, endOffset);
		if (isAngleClockwise(player.facing, endOffset))
		{
			endAng *= -1;
		}

		//sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
		sfw::drawLine(	400 + cos(startAng + facingAng) * startMag,
						300 + sin(startAng + facingAng) * startMag,
						400 + cos(endAng + facingAng) * endMag,
						300 + sin(endAng + facingAng) * endMag);

	}

	return 0;
}