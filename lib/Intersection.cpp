//
// Created by lunar on 06/10/18.
//

#include "Intersection.hpp"

#include "Ray.hpp"
#include "RenderObject.hpp"
#include "Scene.hpp"

Intersection::Intersection(RenderObject *obj, Vec3f intersection, Vec3f normal, Vec3f inAngle, Scene &scene)
		: _obj(obj), _pos(intersection) , _normal(normal), _inAngle(inAngle), _col(_obj->baseColour()), _scene(&scene) {

	_outAngle = (inAngle - _normal * (2 * _inAngle.dotProduct(_normal))).normalize();

}

Colour Intersection::color() {
	return _col;
}

Ray Intersection::outRay() {
	return {_pos + _normal*1e-4, _outAngle};
}

void Intersection::calcShading() {

	_col = {0,0,0};

	for (auto& light : _scene->getLights()) {
		float lightStr = light->effectiveLightStrength(*_scene, _pos + _normal*1e-4);
		Colour dCol = _obj->baseColour() * lightStr * std::max(0.0f, _normal.dotProduct((light->pos() - _pos).normalize()));
		_col += dCol;
	}

}