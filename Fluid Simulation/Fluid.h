#pragma once

#include <math.h>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Fluid {
	int size;
	float dt;
	float diff;
	float visc;

	float* s;
	float* density;

	float* Vx;
	float* Vy;

	float* Vx0;
	float* Vy0;

	//const N;

public:
	Fluid(int size, int diffusion, int viscosity, float dt);
	~Fluid();
	void step();
	void addDensity(int x, int y, float amount);
	void addVelocity(int x, int y, float amountX, float amountY);
	void lin_solve(int b, float* x, float* x0, float a, float c, int iter, int N);
	void diffuse(int b, float* x, float* x0, float diff, float dt, int iter, int N);
	void project(float* velocX, float* velocY, float* p, float* div, int iter, int N);
	void advect(int b, float* d, float* d0, float* velocX, float* velocY, float dt, int N);
	void set_bnd(int b, float* x, int N);
	int IX(int x, int y);
	void render(Vector2f const& p, RenderWindow& window);
};