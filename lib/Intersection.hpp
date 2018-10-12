//
// Created by lunar on 06/10/18.
//

#ifndef RAYTRACING_INTERSECTION_HPP
#define RAYTRACING_INTERSECTION_HPP

#include <memory>

#include <SFML/Graphics/Color.hpp>

#include "Vec3f.hpp"
#include "Colour.hpp"

class Ray;
class RenderObject;
class Scene;

class Intersection {

	RenderObject *_obj;
	Vec3f _pos;
	Vec3f _normal;
	Vec3f _inAngle, _outAngle;

	Colour _col;

	Scene* _scene;

public:
	Intersection(RenderObject *obj, Vec3f intersection, Vec3f normal, Vec3f inAngle, Scene &scene);

	Colour color();

	const Vec3f &pos() const { return _pos; }

	const RenderObject& obj() { return *_obj; }

	const Vec3f &normal() const { return _normal; }
	Vec3f normal() { return _normal; }

	void calcShading();

	Ray outRay();

};


#endif //RAYTRACING_INTERSECTION_HPP
