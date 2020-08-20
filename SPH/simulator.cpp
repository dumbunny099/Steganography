#include "simulator.h"

simulator::simulator(float radius, float mass,float h, int boundary, int number) {
	this->radius = radius;
	this->mass = mass;
	this->boundary = boundary;
	g = 0.01;
	h = 3.0;
	gravity = vec3d(0, -9.8, 0) * g;
	for (int i = 0; i < number; i++) {
		particles.push_back(particle(boundary));
	}
	int arraySize = ceil(boundary / h);
	neighbor = new vector<particle> * *[arraySize];
	for (int i = 0; i < arraySize; i++) {
		neighbor[i] = new vector<particle> * [arraySize];
		for (int j = 0; j < arraySize; j++) {
			neighbor[i][j] = new vector<particle>[arraySize];
		}
	}
}

particle::~particle() {};

void simulator::simulate() {
	for (int i = 0; i < particles.size(); i++){

	}
}

void simulator::findNeighbor(particle pt) {
	neighbors.clear();
	int arraySize = ceil(boundary / h);
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < arraySize; j++) {
			for (int k = 0; k < arraySize; k++) {
				neighbor[i][j][k].clear();
			}
		}
	}
	for (int i = 0; i < particles.size(); i++) {

	}
}