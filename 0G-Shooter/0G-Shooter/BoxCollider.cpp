#include "BoxCollider.h"



#include <cmath>

#include "sfwdraw.h"

#include "Box.h"
#include "CircleCollider.h"



BoxCollider::BoxCollider()
{
	pos = { 0,0 };
	size = { 10,10 };

	canMove = false;
	vel = { 0,0 };
	drag = 0.99f;
	mass = 10;
}


BoxCollider::~BoxCollider()
{
}



void BoxCollider::update()
{
	vel *= canMove;
	pos += vel * sfw::getDeltaTime() * canMove;

	vel *= drag;
}
void BoxCollider::draw(vec2 playerPos, vec2 playerFacing)
{
	Box::draw(playerPos, playerFacing, pos, size);
}

vec2 BoxCollider::getCenter()
{
	return{ pos.x + size.x / 2, pos.y + size.y / 2 };
}

bool BoxCollider::collide(BoxCollider& a, CircleCollider& b)
{
	/*if ((b.pos.x >= a.pos.x && b.pos.x <= a.pos.x + a.size.x &&
		b.pos.y >= a.pos.y && b.pos.y <= a.pos.y + a.size.y) ||
		true)*/
	bool ret = false;

	vec2 center = a.getCenter();

	vec2 dist = { b.pos.x - a.pos.x, b.pos.y - a.pos.y };

	if (dist.x > (a.size.x / 2 + b.radius))
	{
		ret = true;
	}
	else if (dist.y > (a.size.y / 2 + b.radius))
	{
		ret = true;
	}
	else if (dist.x <= (a.size.x / 2))
	{
		ret = true;
	}
	else if (dist.y <= (a.size.y / 2))
	{
		ret = true;
	}
	else
	{
		vec2 distt = { dist.x - a.size.x / 2, dist.y - a.size.y / 2 };
		if (distt.x * distt.x + distt.y + distt.y <= b.radius * b.radius)
		{
			ret = true;
		}
	}

	if(ret)
	{
		float v1x = (a.vel.x * (a.mass - b.mass) + (2 * b.mass * b.vel.x) / (a.mass + b.mass));
		float v2x = (b.vel.x * (b.mass - a.mass) + (2 * a.mass * a.vel.x) / (b.mass + a.mass));
		float v1y = (a.vel.y * (a.mass - b.mass) + (2 * b.mass * b.vel.y) / (a.mass + b.mass));
		float v2y = (b.vel.y * (b.mass - a.mass) + (2 * a.mass * a.vel.y) / (b.mass + a.mass));

		a.vel = { v1x, v1y };
		b.vel = { v2x, v2y };
	}

	return ret;;
}
bool BoxCollider::collide(CircleCollider& a, BoxCollider& b)
{
	return collide(b, a);
}
