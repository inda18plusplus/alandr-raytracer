//
// Created by lunar on 06/10/18.
//

#include "Camera.hpp"

Camera::Camera() : Camera({}, {}) {

}

Camera::Camera(const Vec3f &pos, const Vec3f &dir) : Camera(pos, dir, 90, 90/1.33f, 0) {

}

Camera::Camera(const Vec3f &pos, const Vec3f &dir, float vfow, float hfow, float rotation = 0)
		: _pos(pos), _dir(dir.normalize()), _hfow(hfow), _vfow(vfow), _rotation(rotation) {

}