//
// Created by lunar on 05/10/18.
//

#include "Ray.hpp"

#include <memory>
#include <vector>

#include "Intersection.hpp"
#include "Scene.hpp"

Ray::Ray(const Vec3f &origin, const Vec3f &direction) : _origin(origin), _direction(direction.normalize()) {

}

std::unique_ptr<std::vector<Intersection>> Ray::getIntersections(const Scene &scene) {

	std::unique_ptr<std::vector<Intersection>> intersections(new std::vector<Intersection>);

	for(auto obj : scene.getObjects()) {
		auto ret = obj->intersection(*this);
		if(ret)
			intersections->emplace_back(std::move(*ret));
	}

	return intersections;

}

std::optional<Colour> Ray::trace(const Scene &scene) {
	return trace(scene, 0);
}
std::optional<Colour> Ray::trace(const Scene &scene, int level) {

	if(level >= MAX_TRACE) {
		return {};
	}

	auto intersections = getIntersections(scene);

	if(intersections->empty())
		return {{0, 0, 0}};

	std::sort(intersections->begin(), intersections->end(), [this](Intersection& v1, Intersection& v2){
		return v1.pos().distance(_origin) < v2.pos().distance(_origin);
	});

	auto& closestIntersection = (*intersections)[0];

	closestIntersection.calcShading();

	if (level == MAX_TRACE)
		return closestIntersection.color();

	//TODO: Actual lighting
	if(closestIntersection.obj().reflectivity() == 0)
		return closestIntersection.color();

	auto outRay = closestIntersection.outRay();
	auto nextBounce = outRay.trace(scene, level + 1);

	if(!nextBounce)
		return closestIntersection.color();

	auto col = closestIntersection.color().interpolate(closestIntersection.obj().reflectivity(), *nextBounce);

	return col;

}