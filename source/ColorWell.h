#ifndef COLORWELL_H
#define COLORWELL_H

#include "Color.h"

class ColorWell
{
public:
	ColorWell(Color c, float radius, float mass, float pos, float vel);
	ColorWell(int end);

	Color GetColor();

	float GetRadius();
	float GetMass();
	float GetPos();

	void Update(float dt);

private:
	Color c;
	float radius, mass;
	float pos, vel;
};

#endif
