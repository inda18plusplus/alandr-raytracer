//
// Created by lunar on 09/10/18.
//

#ifndef RAYTRACING_PLANE_HPP
#define RAYTRACING_PLANE_HPP

#include "RenderObject.hpp"
#include "Vec3f.hpp"

class Plane : public RenderObject {

	Vec3f _pos;
	Vec3f _normal;

	Vec3f normal(const Vec3f&) const override {	return _normal;	}

public:
	Plane(Scene *scene, const Vec3f &pos, const Vec3f &normal);

	std::optional<Intersection> intersection(const Ray &ray) override;

};


#endif //RAYTRACING_PLANE_HPP
