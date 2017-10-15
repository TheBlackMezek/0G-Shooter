#pragma once


#include "MathLib\Vec2.h"


class Box
{
public:
	Box();
	~Box();

	void draw(vec2 playerPos, vec2 playerFacing);
	static void draw(vec2 playerPos, vec2 playerFacing, vec2 pos, vec2 size);
	
	vec2 pos;
	vec2 size;
};

