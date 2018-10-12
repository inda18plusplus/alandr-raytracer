//
// Created by lunar on 05/10/18.
//

#ifndef RAYTRACING_SPHERE_HPP
#define RAYTRACING_SPHERE_HPP

#include <SFML/Graphics/Color.hpp>

#include "Vec3f.hpp"
#include "RenderObject.hpp"
#include "util.hpp"


class Sphere : public RenderObject {

	Vec3f _centre;
	float _radius;

	Vec3f normal(const Vec3f &vec) const override;

public:
	Sphere();
	Sphere(Scene *scene, const Vec3f &centre, float radius);

	std::optional<Intersection> intersection(const Ray &ray) override;

};


#endif //RAYTRACING_SPHERE_HPP
