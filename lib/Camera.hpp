//
// Created by lunar on 06/10/18.
//

#ifndef RAYTRACING_CAMERA_HPP
#define RAYTRACING_CAMERA_HPP


#include "Vec3f.hpp"

class Camera {

	Vec3f _pos;
	Vec3f _dir;

	float _hfow;
	float _vfow;
	float _rotation;

public:
	Camera();
	Camera(const Vec3f &pos, const Vec3f &dir);
	Camera(const Vec3f &pos, const Vec3f &dir, float vfow, float hfow, float rotation);

	const Vec3f &pos() const { return _pos; }
	const Vec3f &dir() const { return _dir;	}
	float hfow() const { return _hfow; }
	float vfow() const { return _vfow; }
	float rotation() const { return _rotation; }

	void setPos(const Vec3f &pos) {
		Camera::_pos = pos;
	}
	void setDir(const Vec3f &dir) {
		Camera::_dir = dir;
	}
	void setHfow(float hfow) {
		Camera::_hfow = hfow;
	}
	void setVfow(float vfow) {
		Camera::_vfow = vfow;
	}
	void setRotation(float rotation) {
		Camera::_rotation = rotation;
	}

};


#endif //RAYTRACING_CAMERA_HPP
