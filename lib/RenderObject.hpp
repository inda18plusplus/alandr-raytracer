//
// Created by lunar on 05/10/18.
//

#ifndef RAYTRACING_RENDEROBJECT_HPP
#define RAYTRACING_RENDEROBJECT_HPP

#include <optional>

#include "Ray.hpp"
#include "Vec3f.hpp"
#include "Intersection.hpp"
#include "Colour.hpp"

class Scene;

class RenderObject {

	Scene* _scene;

	Colour _baseColour;

	float _reflectivity = 0.0f;
public:

	//Get the unit normal at the specified vector if one exists
	virtual Vec3f normal(const Vec3f &vec) const = 0;
	RenderObject(Scene* scene);
	virtual ~RenderObject() = default;

	//Check if the ray intersects the Object and optionally return the (closest non-negative) point of intersection
	virtual std::optional<Intersection> intersection(const Ray &ray) = 0;

	const Colour &baseColour() const {
		return _baseColour;
	}
	RenderObject& setBaseColour(const Colour &baseColour) {
		_baseColour = baseColour;
		return *this;
	}

	float reflectivity() const {
		return _reflectivity;
	}
	RenderObject& setReflectivity(float reflectivity) {
		_reflectivity = reflectivity;
		return *this;
	}

	Scene& scene() { return *_scene; }
	RenderObject& setScene(Scene& scene) {
		_scene = &scene;
		return *this;
	}

};


#endif //RAYTRACING_RENDEROBJECT_HPP
