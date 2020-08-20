#pragma once
#include "vec3d.h"
class particle {
public:
	vec3d position;
	vec3d velocity;
	float density;
	particle(int);
	~particle();
	void collision_boundary(float,int);
	void draw();
	void movement(vec3d, float);
};