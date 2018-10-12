//
// Created by lunar on 09/10/18.
//

#include "Plane.hpp"

#include <cmath>
#include <optional>

Plane::Plane(Scene *scene, const Vec3f &pos, const Vec3f &normal) : RenderObject(scene), _pos(pos), _normal(normal.normalize()) {

}

std::optional<Intersection> Plane::intersection(const Ray &ray) {

	const Vec3f& orig = ray.getOrigin();
	const Vec3f& dir = ray.getDirection();

	float t = 0;
	float denom = dir.dotProduct(_normal);

	if(denom > 1e-4) {
		return {};
	}

	t = _normal.dotProduct(_pos - orig) / denom;

	if(t < 0 || isinff(t))
		return {};

	Vec3f intersection = orig + dir * t;
	return std::make_optional<Intersection>(this, intersection, _normal, dir, scene());

}
