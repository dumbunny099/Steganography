#include "particle.h"
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
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
	float damp = 0.9;
	
	if (position.x < 0 && velocity.x<0) {
		position.x = radius;
		velocity.x *= (-1 * damp);
	}
	else if (position.x > boundary&& velocity.x > 0) {
		position.x = boundary - radius;
		velocity.x *= (-1 * damp);
	}
	if (position.y < 0 && velocity.y < 0) {
		position.y = radius;
		velocity.y *= (-1 * damp);
	}
	else if (position.y > boundary && velocity.y > 0) {
		position.y = boundary - radius;
		velocity.y *= (-1 * damp);
	}
	if (position.z < 0 && velocity.z < 0) {
		position.z = radius;
		velocity.z *= (-1 * damp);
	}
	else if (position.z > boundary&& velocity.z > 0) {
		position.z = boundary - radius;
		velocity.z *= (-1 * damp);
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