
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

	CircleCollider c1;
	c1.pos = { 100, 500 };
	c1.radius = 10;
	c1.canMove = false;

	

	while (sfw::stepContext())
	{
		
		player.applyInput();

		emitter.update();

		c1.update();




		CircleCollider::collide(player.collider, c1);



		player.update();



		player.draw();

		//sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
		//sfw::drawCircle(player.x, player.y, 20);

		emitter.draw(player.collider.pos, player.facing);

		c1.draw(player.collider.pos, player.facing);

		Box::draw(player.collider.pos, player.facing, { 100, 100 }, { 80, 40 });
		Box::draw(player.collider.pos, player.facing, { 500, 100 }, { 20, 90 });

	}

	return 0;
}