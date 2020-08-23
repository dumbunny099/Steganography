#pragma once
#include <vector>
#include "particle.h"
#include "SPH.h"

class simulator {
public:
	float radius;
	float mass;
	int boundary;
	float g;
	float h;
	float k;
	float mu;
	vec3d gravity;
	vector<particle> particles = vector<particle>();
	vector<int>*** neighbor;
	vector<float> dens;

	simulator(float, float,float, int,int);
	~simulator();
	void simulate();
	void collision(int,int );
	void draw();
	void setNeighbor();
	vector<int> findNeighbor(int);

	float density(int, vector<int>);
	vec3d pressure(int, vector<int>);
	vec3d viscosity(int, vector<int>);
};