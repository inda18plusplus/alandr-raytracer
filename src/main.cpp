#include <iostream>
#include <SFML/Graphics/Image.hpp>
#include <memory>

#include "Vec3f.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Plane.hpp"
#include "Light.hpp"

int main() {

	std::shared_ptr<sf::Image> image(new sf::Image);
	image->create(1024, 1024);

	Scene scene;

	scene.transferObject(new Plane(&scene, { 5, 0, 0}, {-1, 0, 0}))->setBaseColour({0x8f, 0x00, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, {-5, 0, 0}, { 1, 0, 0}))->setBaseColour({0x8f, 0x00, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, { 0, 5, 0}, { 0,-1, 0}))->setBaseColour({0x00, 0x8f, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, { 0,-5, 0}, { 0, 1, 0}))->setBaseColour({0x00, 0x8f, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, { 0, 0, 5}, { 0, 0,-1}))->setBaseColour({0x00, 0x00, 0x8f}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, { 0, 0,-5}, { 0, 0, 1}))->setBaseColour({0x00, 0x00, 0x8f}).setReflectivity(.1);

	scene.transferObject(new Sphere(&scene, { 0,-4, 0}, 1))->setBaseColour({0x8f, 0x8f, 0x8f}).setReflectivity(.5);
	scene.transferObject(new Sphere(&scene, {-4,-4, 4}, 1))->setBaseColour({0x8f, 0x00, 0x8f});

	scene.transferLight(new Light({ 4.0f,4.0f,0.0f}, 500.0f));
	scene.transferLight(new Light({-4.0f,4.0f,0.0f}, 500.0f));

	scene.renderTo(image, {{0, -3, -4},{1,0,0}}); //Do not touch the second vector, it won't work, and might bugger everything

	image->saveToFile("out.png");

	return 0;
}