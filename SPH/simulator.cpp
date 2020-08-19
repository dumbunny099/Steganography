#include "simulator.h"

simulator::simulator(int num,int size,float mass, float radius) {
	for (int i = 0; i < num; i++) {
		particles.push_back(new particle(size,mass, radius));
	}
	number = num;
	this->size = size;
	gravityConstant = 0.01;
	force = gravityConstant * vec3d(0, 9.8, 0);
}

simulator::~simulator() {};
void simulator::simulation() {
	for (int i = 0; i < particles.size(); i++) {
		for (int j = 0; j < particles.size(); j++) {
			if (particles[i] != particles[j]) {
				particles[i]->collision(particles[j],this->size);
			}
		}
		particles[i]->movement(gravityConstant*force);
	}
	
}

void simulator::draw() {
	cout << "draw~~" << endl;
	cout << particles.size() << endl;
	for (int i = 0; i < particles.size(); i++)
		particles[i]->draw();
}