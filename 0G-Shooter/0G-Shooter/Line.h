#pragma once


#include "MathLib\Vec2.h"


class Line
{
public:
	Line();
	~Line();

	vec2 start;
	vec2 end;

	void draw(vec2 playerPos, vec2 playerFacing);
	static void draw(vec2 playerPos, vec2 playerFacing, vec2 start, vec2 end);
};

