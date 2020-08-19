#pragma once
#include "vec3d.h"

class particle {
public:
	float mass;
	float radius;
	vec3d position;
	vec3d velocity;
	particle(int,float,float);
	~particle();
	
	void collision(particle*,int size);
	void movement(vec3d);
	void draw();
};
void collision_boundary(particle*,int size);
