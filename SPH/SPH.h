#pragma once
#include <vector>
#include "particle.h"

float poly6(vec3d, int);
vec3d spiky(vec3d, int);
float viscosityKernel(vec3d, int);

float getDensity(vec3d, vector<particle*>);
vec3d getPressure(vec3d, vector<particle*>);
vec3d getViscosity(vec3d, vector<particle*>);