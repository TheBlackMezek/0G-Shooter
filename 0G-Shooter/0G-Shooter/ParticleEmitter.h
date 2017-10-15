#pragma once


#include <vector>

#include "MathLib\Vec2.h"



struct Particle
{
	vec2 pos;
	vec2 vel;
	float livedTime;
};

class ParticleEmitter
{
public:
	ParticleEmitter(int max);
	~ParticleEmitter();

	vec2 pos;
	vec2 velMin;
	vec2 velMax;
	float lifeMax;
	float wait;

	void update();
	void draw(vec2 playerPos, vec2 playerFacing);

private:
	int maxParticles;
	std::vector<Particle> particles;

	float waited;
};

