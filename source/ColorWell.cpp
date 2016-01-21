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

	this->c = Color::HSL(rand() % 360, 1.f, 0.5f);
	this->radius = 1 + (rand() % 50)/10.f;
	this->mass = this->radius;
	this->pos = (dir > 0) ? 0 : (end - 1);
	this->vel = (1000 + (rand() % 4000)) / 100.f;
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
