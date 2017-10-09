#pragma once
class Player
{
public:
	Player();
	~Player();

	float x;
	float y;
	float speed;

	void update();

	void draw();
};

