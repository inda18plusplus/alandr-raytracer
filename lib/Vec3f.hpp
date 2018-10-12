//
// Created by lunar on 05/10/18.
//

#ifndef RAYTRACING_VEC3F_HPP
#define RAYTRACING_VEC3F_HPP

#include <iostream>

class Vec3f {

	float _v[3];

public:
	Vec3f();
	Vec3f(float x, float y, float z);

	Vec3f(const Vec3f& copy);

	float &operator[](int index);
	float operator[](int index) const;

	Vec3f operator+(const Vec3f& v2) const;
	Vec3f operator-(const Vec3f& v2) const;
	Vec3f operator*(float scale) const;
	Vec3f operator/(float scale) const;
	Vec3f operator-() const;

	Vec3f operator*(const Vec3f& v2) const;

	const Vec3f &operator+=(const Vec3f& v2);
	const Vec3f &operator-=(const Vec3f& v2);
	const Vec3f &operator*=(float scale);
	const Vec3f &operator/=(float scale);

	float mag() const;
	Vec3f normalize() const;
	float dotProduct(const Vec3f& v2) const;
	Vec3f crossProduct(const Vec3f& v2) const;
	float sqr() const;

	float distance(const Vec3f &v2) const {
		return (*this - v2).mag();
	}

	friend std::ostream& operator<<(std::ostream& os, const Vec3f& v);

};

std::ostream& operator<<(std::ostream& os, const Vec3f& v);

#endif //RAYTRACING_VEC3F_HPP
