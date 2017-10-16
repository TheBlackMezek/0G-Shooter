#include "CircleCollider.h"


#include "sfwdraw.h"

#include "Circle.h"


CircleCollider::CircleCollider()
{
	pos = { 0, 0 };
	radius = 2;

	canMove = false;
	vel = { 0, 0 };
	drag = 1;
	mass = 10;
}


CircleCollider::~CircleCollider()
{
}




void CircleCollider::update()
{
	vel *= canMove;
	pos += vel * sfw::getDeltaTime() * canMove;


}

void CircleCollider::draw(vec2 playerPos, vec2 playerFacing)
{
	Circle::draw(playerPos, playerFacing, pos, radius);
}



bool CircleCollider::collide(CircleCollider& a, CircleCollider& b)
{
	if ((a.pos.x + a.radius + b.radius > b.pos.x &&
		b.pos.x + a.radius + b.radius > a.pos.x &&
		a.pos.y + a.radius + b.radius > b.pos.y &&
		b.pos.y + a.radius + b.radius > a.pos.y) &&
		//theoretical AABBs are overlapping, possible collision
		(distance(a.pos, b.pos) < a.radius + b.radius)
		//confirmed collision
		)
	{
		a.vel.x = (a.vel.x * (a.mass - b.mass) + (2 * b.mass * a.vel.x) / (a.mass + b.mass));
		b.vel.x = (b.vel.x * (b.mass - a.mass) + (2 * a.mass * b.vel.x) / (b.mass + a.mass));
		a.vel.y = (a.vel.y * (a.mass - b.mass) + (2 * b.mass * a.vel.y) / (a.mass + b.mass));
		b.vel.y = (b.vel.y * (b.mass - a.mass) + (2 * a.mass * b.vel.y) / (b.mass + a.mass));
	}
}
