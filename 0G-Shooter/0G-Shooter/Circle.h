#pragma once

#include "MathLib\Vec2.h"

class Circle
{
public:
	Circle();
	~Circle();

	vec2 pos;
	float radius;

	void draw(vec2 playerPos, vec2 playerFacing);
	static void draw(vec2 playerPos, vec2 playerFacing, vec2 pos, float radius);
};

