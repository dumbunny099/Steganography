#include "simulator.h"

simulator::simulator(float radius, float mass,float h, int boundary, int number) {
	this->radius = radius;
	this->mass = mass;
	this->boundary = boundary;
	g = 0.01;
	this->h = 3.0;
	gravity = vec3d(0, -9.8, 0) * g;
	for (int i = 0; i < number; i++) {
		particles.push_back(particle(boundary));
	}
	int arraySize = ceil(boundary / h);
	neighbor = new vector<int> * *[arraySize];
	for (int i = 0; i < arraySize; i++) {
		neighbor[i] = new vector<int> * [arraySize];
		for (int j = 0; j < arraySize; j++) {
			neighbor[i][j] = new vector<int>[arraySize];
		}
	}
}

void simulator::simulate() {
	//setNeighbor();
	for (int i = 0; i < particles.size(); i++){
		vector<int> neighbors = findNeighbor(i);
		for (int j = 0; j < neighbors.size(); j++) {
			collision(i, j);
		}
		particles[i].movement(gravity, mass);
		particles[i].collision_boundary(radius,boundary);
	}
}

void simulator::setNeighbor() {
	int arraySize = ceil(boundary / h);
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < arraySize; j++) {
			for (int k = 0; k < arraySize; k++) {
				neighbor[i][j][k].clear();
			}
		}
	}
	for (int i = 0; i < particles.size(); i++) {
		int _x = int(particles[i].position.x);
		int _y = int(particles[i].position.y);
		int _z = int(particles[i].position.z);
		if (_x < 0)_x = 0;
		else if (_x > arraySize - 1)_x = arraySize - 1;
		if (_y < 0)_y = 0;
		else if (_y > arraySize - 1)_y = arraySize - 1;
		if (_z < 0)_z = 0;
		else if (_z > arraySize - 1)_z = arraySize - 1;
		neighbor[_x][_y][_z].push_back(i);
	}
}

vector<int> simulator::findNeighbor(int index) {
	int arraySize = ceil(boundary / h);
	vector<int> neighbors;
	particle pt = particles[index];
	for (int _x = int(pt.position.x) -1; _x <= int(pt.position.x) + 1; _x++) {
		for (int _y = int(pt.position.y) - 1; _y <= int(pt.position.y) + 1; _y++) {
			for (int _z = int(pt.position.z) - 1; _z <= int(pt.position.z) + 1; _z++) {
				if (_x<0 || _x >arraySize - 1 || _y<0 || _y >arraySize - 1 || _z<0 || _z >arraySize - 1)continue;
				cout << neighbor[_x][_y][_z].size() << endl;
				for (int i = 0; i < neighbor[_x][_y][_z].size(); i++) {
					neighbors.push_back(neighbor[_x][_y][_z][i]);
				}
			}
		}
	}
	return neighbors;
}
simulator::~simulator() {};
void simulator::collision(int p1, int p2) {
	float dist = distance(particles[p1].position,particles[p2].position);
	if (dist < 2 * radius && dist != 0.0) {
		vec3d unit_dir = particles[p1].position - particles[p2].position;
		unit_dir.normalize();
		vec3d proj1 = particles[p1].velocity.proj(unit_dir);
		vec3d proj2 = particles[p2].velocity.proj(unit_dir * -1);
		particles[p1].velocity = particles[p1].velocity - proj1 + proj2;
		particles[p2].velocity = particles[p2].velocity + proj1 - proj2;
		particles[p1].position = particles[p1].position + unit_dir * (radius - dist / 2);
		particles[p2].position = particles[p2].position - unit_dir * (radius - dist / 2);
	}
	
	
}

void simulator::draw() {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
}