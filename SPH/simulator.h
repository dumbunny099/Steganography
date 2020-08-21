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
	vec3d gravity;
	vector<particle> particles = vector<particle>();
	vector<int>*** neighbor;

	simulator(float, float,float, int,int);
	~simulator();
	void simulate();
	void collision(int,int );
	void draw();
	void setNeighbor();
	vector<int> findNeighbor(int);
};