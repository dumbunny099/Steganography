#pragma once
#include <vector>
#include "particle.h"

class simulator {
public:
	float number;
	float size;
	float gravityConstant;
	vec3d force;
	vector<particle*> particles;
	simulator(int,int,float,float);
	~simulator();
	void simulation();
	void draw();
};
