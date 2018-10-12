//
// Created by lunar on 12/10/18.
//

#include "Light.hpp"

#include <cmath>

#include "Ray.hpp"
#include "Scene.hpp"
#include "util.hpp"

Light::Light(const Vec3f& pos, float lightStr) : _pos(pos), _lightStrength(lightStr) {



}

float Light::effectiveLightStrength(const Scene& scene, const Vec3f &pos) {

	Vec3f posDifference = _pos - pos;
	Ray traceRay(pos, posDifference.normalize());

	auto intersections = traceRay.getIntersections(scene);

	std::sort(intersections->begin(), intersections->end(), [&pos](Intersection& v1, Intersection& v2){
		return v1.pos().distance(pos) < v2.pos().distance(pos);
	});

	if(pos.distance(_pos) < (*intersections)[0].pos().distance(pos)) {
		float intensity = std::clamp(_lightStrength / (4.0f*M_PI*sqr(pos.distance(_pos))), 0.0, 1.0);
		return intensity;
	}

	return 0;

}