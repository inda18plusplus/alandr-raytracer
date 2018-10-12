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

	/*Sphere s({4,0,0}, 2);

	auto normal = s.normal(Vec3f{1,1,-1}.normalize()*2 + Vec3f{4,0,0});

	std::cout << Vec3f{1,0,0} - s._centre

	return 0;*/

	std::shared_ptr<sf::Image> image(new sf::Image);
	image->create(1024, 1024);

	Scene scene;
	/*scene.transferObject(new Sphere({-4, 0, 60}, 4))->setBaseColour({0x8f, 0, 0x8f});
	scene.transferObject(new Sphere({4, 0, 60}, 4)) ->setBaseColour({0,0x8f,0})     .setReflectivity(.75);

	scene.transferObject(new Plane({0, 0, 80}, {0,1,-1}))  ->setBaseColour({0,0,0})         .setReflectivity(1);
	scene.transferObject(new Plane({0, 200, 0}, {0,-1,0}))->setBaseColour({0x87,0xCE,0xEB}); //"Sky"*/

	scene.transferObject(new Plane(&scene, {5, 0, 0}, {-1, 0, 0}))->setBaseColour({0x8f, 0x00, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, {-5, 0, 0}, {1, 0, 0}))->setBaseColour({0x8f, 0x00, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, {0, 5, 0}, {0, -1, 0}))->setBaseColour({0x00, 0x8f, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, {0, -5, 0}, {0, 1, 0}))->setBaseColour({0x00, 0x8f, 0x00}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, {0, 0, 5}, {0, 0, -1}))->setBaseColour({0x00, 0x00, 0x8f}).setReflectivity(.1);
	scene.transferObject(new Plane(&scene, {0, 0, -5}, {0, 0, 1}))->setBaseColour({0x00, 0x00, 0x8f}).setReflectivity(.1);

	scene.transferObject(new Sphere(&scene, {0, -4, 0}, 1))->setBaseColour({0x8f, 0x8f, 0x8f}).setReflectivity(.5);
	scene.transferObject(new Sphere(&scene, {-4, -4, 4}, 1))->setBaseColour({0x8f, 0x00, 0x8f});

	scene.transferLight(new Light({0,0,0}, 1000.0f));

	scene.renderTo(image, {{0, -3, -4},{1,0,0}}); //Do not touch the second vector, it won't work, and might bugger everything

	image->saveToFile("out.png");

	return 0;
}