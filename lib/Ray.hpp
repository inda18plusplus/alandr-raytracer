//
// Created by lunar on 05/10/18.
//

#ifndef RAYTRACING_RAY_HPP
#define RAYTRACING_RAY_HPP

#include <memory>
#include <optional>
#include <vector>

#include "Colour.hpp"
#include "Vec3f.hpp"

class Scene;
class Intersection;

class Ray {

	Vec3f _origin;
	Vec3f _direction;

	static const int MAX_TRACE = 3;

public:
	Ray(const Vec3f &origin, const Vec3f &direction);

	Vec3f getOrigin() { return _origin; }
	Vec3f getDirection() { return _direction; }
	const Vec3f &getOrigin() const { return _origin; }
	const Vec3f &getDirection() const { return _direction; }
	void setOrigin(const Vec3f &origin) { _origin = origin;	}
	void setDirection(const Vec3f &direction) { _direction = direction.normalize();	}

	std::optional<Colour> trace(const Scene& scene);
	std::unique_ptr<std::vector<Intersection>> getIntersections(const Scene& scene);

private:
	std::optional<Colour> trace(const Scene& scene, int level);

};


#endif //RAYTRACING_RAY_HPP
