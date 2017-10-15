#include "ParticleEmitter.h"


#include "sfwdraw.h"

#include "Circle.h"




ParticleEmitter::ParticleEmitter(int max)
{
	maxParticles = max;
	particles.resize(maxParticles);

	for (int i = 0; i < maxParticles; ++i)
	{
		particles[i].pos = { 0, 0 };
		particles[i].vel = { 0, 0 };
		particles[i].livedTime = -1;
	}

	pos = { 0, 0 };
	velMin = { -100, -100 };
	velMax = { 100, 100 };
	lifeMax = 2;
	wait = 0.5f;
	waited = 0;
}


ParticleEmitter::~ParticleEmitter()
{
}



void ParticleEmitter::update()
{
	float delta = sfw::getDeltaTime();
	waited += delta;

	for (int i = 0; i < maxParticles; ++i)
	{
		if (particles[i].livedTime >= 0)
		{
			particles[i].livedTime += delta;
			if (particles[i].livedTime <= lifeMax)
			{
				particles[i].pos += particles[i].vel * delta;
			}
			else
			{
				particles[i].livedTime = -1;
			}
		}
	}

	while (waited >= wait)
	{
		waited -= wait;

		for (int i = 0; i < maxParticles; ++i)
		{
			if (particles[i].livedTime < 0)
			{
				particles[i].pos = pos;
				vec2 vel;
				particles[i].vel = velMax;
				particles[i].livedTime = 0;
				break;
			}
		}
	}
}

void ParticleEmitter::draw(vec2 playerPos, vec2 playerFacing)
{
	for (int i = 0; i < maxParticles; ++i)
	{
		if (particles[i].livedTime >= 0)
		{
			Circle::draw(playerPos, playerFacing, particles[i].pos, 5);
		}
	}
}

