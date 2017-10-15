
#define _USE_MATH_DEFINES
#include <cmath>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"

#include "Player.h"
#include "Box.h"
#include "Circle.h"
#include "ParticleEmitter.h"



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

	ParticleEmitter emitter(10);

	

	while (sfw::stepContext())
	{
		
		player.update();
		vec2 ppos;
		ppos.x = player.x;
		ppos.y = player.y;

		emitter.update();




		player.draw();

		//sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
		//sfw::drawCircle(player.x, player.y, 20);

		emitter.draw(ppos, player.facing);

		Box::draw(ppos, player.facing, { 100, 100 }, { 80, 40 });
		Box::draw(ppos, player.facing, { 500, 100 }, { 20, 90 });
		Circle::draw(ppos, player.facing, { 100, 500 }, 10);

	}

	return 0;
}