#include "Box.h"


#include "Line.h"


Box::Box()
{
	pos.x = 0;
	pos.y = 0;
	size.x = 0;
	size.y = 0;
}


Box::~Box()
{
}



void Box::draw(vec2 playerPos, vec2 playerFacing)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };
	Line::draw(playerPos, playerFacing, botLeft, botRight);
	Line::draw(playerPos, playerFacing, botRight, topRight);
	Line::draw(playerPos, playerFacing, topRight, topLeft);
	Line::draw(playerPos, playerFacing, topLeft, botLeft);
}

void Box::draw(vec2 playerPos, vec2 playerFacing, vec2 pos, vec2 size)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };
	Line::draw(playerPos, playerFacing, botLeft, botRight);
	Line::draw(playerPos, playerFacing, botRight, topRight);
	Line::draw(playerPos, playerFacing, topRight, topLeft);
	Line::draw(playerPos, playerFacing, topLeft, botLeft);
}
