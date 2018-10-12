//
// Created by lunar on 08/10/18.
//

#ifndef RAYTRACING_COLOUR_HPP
#define RAYTRACING_COLOUR_HPP

#include <SFML/Graphics/Color.hpp>

#include <cstdint>

typedef std::uint8_t uint8_t;
typedef std::uint32_t uint32_t;

struct Colour {

	float _r, _g, _b;
	float _a;

public:
	Colour();
	Colour(float r, float g, float b, float a = 1.0f);

	///Made just to avoid needing an explicit cast for the unsigned char constructor
	///WARNING: Will discard input bytes above 0xff
	Colour(int r, int g, int b, int a = 0xff);
	Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xff);
	Colour(unsigned int rgba);

	Colour operator+(const Colour& col) const;
	Colour operator*(float scalar) const;

	Colour& operator+=(const Colour& col);

	explicit operator sf::Color() const;

	//Interpolate with fraction of other colour (fraction is how much of the new colour should be the argument)
	Colour interpolate(float fraction, const Colour& other) const;

	void deGamma();

};


#endif //RAYTRACING_COLOUR_HPP
