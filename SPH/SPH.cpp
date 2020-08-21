#include "SPH.h"
const double PI = 3.1415926535897932384626433832795;
float poly6(vec3d r, int h) {
	if (r.mag() >= h) {
		return 0;
	}
	else {
		float constant = 315 / (64 * PI * pow(h, 9));
		float kernel = (pow(pow(h, 2) - pow(r.mag(), 2), 3));
		return constant * kernel;
	}
}

vec3d spiky(vec3d r, int h) {
	if (r.mag() >= h || r.mag() == 0) {
		return vec3d(0,0,0);
	}
	else {
		float constant = 45 / (PI * pow(h, 6) * r.mag());
		vec3d kernel = r * pow(h - r.mag(), 2);
		return kernel * constant;
	}
}

float viscosity(vec3d r, int h) {
	if (r.mag() >= h || r.mag() == 0) {
		return 0;
	}
	else {
		float constant = 45 / (PI * pow(h, 6));
		float kernel = h - r.mag();
		return kernel * constant;
	}
}