#pragma once
#include <vector>
#include "vec3d.h"
#include "particle.h"

class simulator {
public:
	float radius;
	float mass;
	int boundary;
	float g;
	float h;
	vec3d gravity;
	vector<particle> particles;
	vector<particle>*** neighbor;
	vector<particle> neighbors;

	simulator(float, float,float, int,int);
	~simulator();
	void simulate();
	void findNeighbor(particle);
};