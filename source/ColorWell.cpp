#include "ColorWell.h"

ColorWell::ColorWell(Color c, float radius, float mass, float pos, float vel) {
	this->c = c;
	this->radius = radius;
	this->mass = mass;
	this->pos = pos;
	this->vel = vel;
}

ColorWell::ColorWell(int end) {
	int dir = (rand() % 2) ? 1 : -1;
	float hue = (rand() % 36000) / 100.f;

	this->c = Color::HSL(hue, 1.f, 0.5f);
	this->radius = 0.5f + (rand() % 50)/10.f;
	this->mass = 2*this->radius;
	this->pos = (dir > 0) ? 0 : (end - 1);
	this->vel = (5000 + (rand() % 10000)) / 100.f;
	if(dir < 0)
		this->vel *= -1;
}

Color ColorWell::GetColor() {
	return c;
}

float ColorWell::GetRadius() {
	return radius;
}

float ColorWell::GetMass() {
	return mass;
}

float ColorWell::GetPos() {
	return pos;
}

void ColorWell::Update(float dt) {
	pos += dt*vel;
}
