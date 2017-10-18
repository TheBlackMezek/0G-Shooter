#pragma once


#include "MathLib\Vec2.h"

class CircleCollider;


class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	vec2 pos;
	vec2 size;

	bool canMove;
	vec2 vel;
	float drag;
	float mass;



	void update();
	void draw(vec2 playerPos, vec2 playerFacing);
	vec2 getCenter();

	static bool collide(BoxCollider& a, CircleCollider& b);
	static bool collide(CircleCollider& a, BoxCollider& b);
};

