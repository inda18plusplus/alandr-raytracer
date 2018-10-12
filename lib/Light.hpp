//
// Created by lunar on 12/10/18.
//

#ifndef RAYTRACING_LIGHT_HPP
#define RAYTRACING_LIGHT_HPP

#include "Vec3f.hpp"

class Scene;

class Light {

	Vec3f _pos;
	float _lightStrength; //Intensity at the unit sphere around the light

public:
	Light(const Vec3f& pos, float lightStr);

	const Vec3f& pos() { return _pos; }

	float effectiveLightStrength(const Scene& scene, const Vec3f& pos);

};


#endif //RAYTRACING_LIGHT_HPP
