//
// Created by lunar on 05/10/18.
//

#include "Sphere.hpp"

#include <cmath>

Sphere::Sphere() : Sphere(nullptr, {}, 0.0) {

}

Sphere::Sphere(Scene *scene, const Vec3f &centre, float radius) : RenderObject(scene), _centre(centre), _radius(radius) {



}

std::optional<Intersection> Sphere::intersection(const Ray &ray) {

	auto orig = ray.getOrigin() - _centre;
	const auto& dir = ray.getDirection();

	float a = dir.sqr();
	float b = 2*dir.dotProduct(orig);
	float c = orig.sqr() - sqr(_radius);

	float discriminant = b*b - 4*a*c;

	if (discriminant < 0)
		return {};

	float t = 0;

	if(!discriminant) {
		t = (-b/(2*a));
	} else {
		float root1 = (-b + sqrtf(discriminant))/(2*a);
		float root2 = (-b - sqrtf(discriminant))/(2*a);

		t = std::min(root1, root2);
	}

	if(t < 0) {
		return {};
	}

	Vec3f intersection = ray.getOrigin() + dir * t;

	return std::make_optional<Intersection>(this, intersection, normal(intersection), dir, scene());

}

Vec3f Sphere::normal(const Vec3f &vec) const {

	return (vec - _centre).normalize();

}
