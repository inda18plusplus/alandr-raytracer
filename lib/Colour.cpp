//
// Created by lunar on 08/10/18.
//

#include "Colour.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

Colour::Colour() : Colour(0.0f, 0.0f, 0.0f) {

}
Colour::Colour(float r, float g, float b, float a) : _r(r), _g(g), _b(b), _a(a) {

}
Colour::Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
		Colour((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f) {

}
Colour::Colour(int r, int g, int b, int a) : Colour((unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a) {

}
Colour::Colour(unsigned int rgba) :
		Colour(
				(unsigned char)((rgba & 0xff000000) >> 24),
				(unsigned char)((rgba & 0x00ff0000) >> 16),
				(unsigned char)((rgba & 0x0000ff00) >> 8),
				(unsigned char)((rgba & 0x000000ff) >> 0)
		) {

}

Colour Colour::operator+(const Colour &col) const {
	Colour ret = *this;
	return ret += col;
}
Colour Colour::operator*(float scalar) const {

	float newR = std::min(_r * scalar, 1.0f);
	float newG = std::min(_g * scalar, 1.0f);
	float newB = std::min(_b * scalar, 1.0f);

	return {newR, newG, newB};

}

Colour& Colour::operator+=(const Colour &col) {

	_r = std::min(1.0f, col._r + _r);
	_g = std::min(1.0f, col._g + _g);
	_b = std::min(1.0f, col._b + _b);
	_a = std::min(1.0f, col._a + _a);

	return *this;

}

Colour Colour::interpolate(float fraction, const Colour &other) const {

	if(fraction < 0 || fraction > 1.0f)
		throw std::invalid_argument("Scaling by invalid value!");

	float newR = (other._r - _r) * fraction + _r;
	float newG = (other._g - _g) * fraction + _g;
	float newB = (other._b - _b) * fraction + _b;

	return {newR, newG, newB};

}

void Colour::deGamma() {

	/*_r = powf(_r, .45f);
	_g = powf(_g, .45f);
	_b = powf(_b, .45f);*/

}

Colour::operator sf::Color() const {
	return sf::Color(
			std::clamp(_r, 0.0f, 1.0f) * 0xff,
			std::clamp(_g, 0.0f, 1.0f) * 0xff,
			std::clamp(_b, 0.0f, 1.0f) * 0xff,
			std::clamp(_a, 0.0f, 1.0f) * 0xff
			);
}