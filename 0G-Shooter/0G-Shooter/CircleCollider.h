#pragma once


#include "MathLib\Vec2.h"



class CircleCollider
{
public:
	CircleCollider();
	~CircleCollider();

	vec2 pos;
	float radius;

	bool canMove;
	vec2 vel;
	float drag;
	float mass;


	void update();
	void draw(vec2 playerPos, vec2 playerFacing);

	static bool collide(CircleCollider& a, CircleCollider& b);
	static bool intersects(const CircleCollider& a, const vec2 start, const vec2 end);

private:
	static vec2 closestPointOnLineToPoint(vec2 start, vec2 end, vec2 point);
};

