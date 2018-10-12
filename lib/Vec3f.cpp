//
// Created by lunar on 05/10/18.
//

#include "Vec3f.hpp"

#include <cmath>

Vec3f::Vec3f() : Vec3f(0, 0, 0) {

}
Vec3f::Vec3f(float x, float y, float z) : _v{x, y, z} {

}
Vec3f::Vec3f(const Vec3f &copy) : _v{copy._v[0], copy._v[1], copy._v[2]} {

}

float &Vec3f::operator[](int index) {
	return _v[index];
}
float Vec3f::operator[](int index) const {
	return _v[index];
}

Vec3f Vec3f::operator+(const Vec3f &v2) const {
	return {_v[0] + v2._v[0], _v[1] + v2._v[1], _v[2] + v2._v[2]};
}
Vec3f Vec3f::operator-(const Vec3f &v2) const {
	return {_v[0] - v2._v[0], _v[1] - v2._v[1], _v[2] - v2._v[2]};
}
Vec3f Vec3f::operator*(float scale) const {
	return {_v[0] * scale, _v[1] * scale, _v[2] * scale};
}
Vec3f Vec3f::operator/(float scale) const {
	return {_v[0] / scale, _v[1] / scale, _v[2] / scale};
}
Vec3f Vec3f::operator-() const {
	return {-_v[0], -_v[1], -_v[2]};
}

Vec3f Vec3f::operator*(const Vec3f &v2) const {
	return {_v[0] * v2[0], _v[1] * v2[1], _v[2] * v2[2]};
}

const Vec3f &Vec3f::operator+=(const Vec3f &v2) {
	_v[1] += v2._v[1];
	_v[2] += v2._v[2];
	_v[3] += v2._v[3];
	return *this;
}
const Vec3f &Vec3f::operator-=(const Vec3f &v2) {
	_v[1] -= v2._v[1];
	_v[2] -= v2._v[2];
	_v[3] -= v2._v[3];
	return *this;
}
const Vec3f &Vec3f::operator*=(float scale) {
	_v[0] *= scale;
	_v[1] *= scale;
	_v[2] *= scale;
	return *this;
}
const Vec3f &Vec3f::operator/=(float scale) {
	_v[0] /= scale;
	_v[1] /= scale;
	_v[2] /= scale;
	return *this;
}

float Vec3f::mag() const {
	return sqrtf(_v[0] * _v[0] + _v[1] * _v[1] + _v[2] * _v[2]);
}
Vec3f Vec3f::normalize() const {
	Vec3f copy = *this;
	return copy / mag();
}
float Vec3f::dotProduct(const Vec3f &v2) const {
	return _v[0] * v2._v[0] + _v[1] * v2._v[1] + _v[2] * v2._v[2];
}
Vec3f Vec3f::crossProduct(const Vec3f &v2) const {
	return {
		_v[1] * v2[2] + _v[2] * v2[1],
		_v[2] * v2[0] + _v[0] * v2[2],
		_v[0] * v2[1] + _v[1] * v2[0]
	};
}
float Vec3f::sqr() const {
	return dotProduct(*this);
}

std::ostream& operator<<(std::ostream& os, const Vec3f& v) {
	os << '[' << v._v[0] << ' ' << v._v[1] << ' ' << v._v[2] << ']';
	return os;
}