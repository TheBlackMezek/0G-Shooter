#pragma once
class Player
{
public:
	Player();
	~Player();

	float x;
	float y;
	float speed;

	float rotation;
	float rotSpeed;

	void update();

	void draw();
};

