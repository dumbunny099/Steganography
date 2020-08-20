#include "particle.h"
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <iostream>
#include <random>
using namespace std;

particle::particle(int boundary) {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> range(0, boundary);
	position = vec3d(range(gen), range(gen), 0);
	velocity = vec3d(0, 0, 0);
	density = 0;
}

particle::~particle() {};

void particle::collision_boundary(float radius, int boundary) {
	if (position.x < 0) {
		position.x += radius - position.x;
		velocity.x *= -1;
	}
	else if (position.x > boundary) {
		position.x -= radius - boundary + position.x;
		velocity.x * -1;
	}
	if (position.y < 0) {
		position.y += radius - position.y;
		velocity.y *= -1;
	}
	else if (position.y > boundary) {
		position.y -= radius - boundary + position.y;
		velocity.y * -1;
	}
	if (position.z < 0) {
		position.z += radius - position.z;
		velocity.z *= -1;
	}
	else if (position.z > boundary) {
		position.z -= radius - boundary + position.z;
		velocity.z * -1;
	}
}

void particle::draw() {
	glVertex3f(position.x, position.y, position.z);
}

void particle::movement(vec3d force, float mass) {
	vec3d a = force / mass;
	velocity = velocity + a;
	position = position + velocity;
}