#include <iostream>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <random>
#include "particle.h"
using namespace std;

particle::particle(int size, float mass, float radius) {
	random_device rng;
	mt19937 gen(rng());
	uniform_real_distribution<> dis1(0, 2*size);
	position = vec3d(dis1(gen),dis1(gen),dis1(gen));
	uniform_real_distribution<> dis2(0, 1.0);
	velocity = vec3d(dis2(gen), dis2(gen), dis2(gen));
	this->mass = mass;
	this->radius = radius;
}

particle::~particle() {};

void collision_boundary(particle* particle, int size) {
	if (particle->position.x < 0) {
		particle->position.x += particle->radius - particle->position.x;
		particle->velocity.x *= -1;
	}
	else if (particle->position.x > 2*size) {
		particle->position.x -= particle->radius + particle->position.x - 2*size;
		particle->velocity.x *= -1;
	}
	if (particle->position.y < 0) {
		particle->position.y += particle->radius + particle->position.y;
		particle->velocity.y *= -1;
	}
	else if (particle->position.y > 2*size) {
		particle->position.y -= particle->radius + particle->position.y - 2*size;
		particle->velocity.y *= -1;
	}
	if (particle->position.z < 0) {
		particle->position.z += particle->radius + particle->position.z;
		particle->velocity.z *= -1;
	}
	else if (particle->position.z > 2*size) {
		particle->position.z -= particle->radius + particle->position.z - 2*size;
		particle->velocity.z *= -1;
	}
}

void particle::collision(particle* other,int size) {
	float dist = distance(this->position,other->position);
	if (dist < 2 * this->radius) {
		vec3d unit_dir = (this->position - other->position);
		unit_dir.normalize();
		vec3d vec1Proj = this->velocity.proj(unit_dir);
		vec3d vec2Proj = other->velocity.proj(unit_dir.inverse());
		this->velocity = this->velocity - vec1Proj + vec2Proj;
		other->velocity = other->velocity - vec2Proj + vec1Proj;
		this->position = this->position + unit_dir * (2 * radius - dist);
		other->position = other->position - unit_dir * (2 * radius - dist);
		collision_boundary(this,size);
		collision_boundary(other,size);
	}
}

void particle::movement(vec3d force){
	vec3d acc = force / mass;
	velocity = velocity + acc;
	position = position + velocity;
}

void particle::draw() {
	glVertex3f(position.x,position.y,position.z);
	cout << position << endl;
}