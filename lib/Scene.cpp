//
// Created by lunar on 06/10/18.
//

#include "Scene.hpp"

#include <algorithm>

#include <SFML/Graphics/Image.hpp>

std::shared_ptr<RenderObject> Scene::transferObject(RenderObject *obj) {
	std::shared_ptr<RenderObject> ptr(obj);
	_objects.push_back(ptr);

	return ptr;
}
std::shared_ptr<Light> Scene::transferLight(Light *light) {
	std::shared_ptr<Light> ptr(light);
	_lights.push_back(ptr);

	return ptr;
}

std::shared_ptr<sf::Image> Scene::render(unsigned int width, unsigned int height, const Camera &cam) {
	std::shared_ptr<sf::Image> image(new sf::Image);
	image->create(width, height);

	renderTo(image, cam);

	return image;
}

void Scene::renderTo(std::shared_ptr<sf::Image> image, const Camera &cam) {

	long sizeX = image->getSize().x;
	long sizeY = image->getSize().y;
	float dX = 1.0f/sizeX;
	float dY = 1.0f/sizeY;

	for (unsigned int x = 0; x < image->getSize().x; ++x) {
		for (unsigned int y = 0; y < image->getSize().y; ++y) {

			Vec3f dir((dX*(x-sizeX*.5))*2, (-dY*(y-sizeY*.5))*2, 1);
			Ray r(cam.pos(), dir);

			auto ret = r.trace(*this);
			if(ret) {
				ret->deGamma();
				image->setPixel(x, y, static_cast<sf::Color>(*ret));
			}


			/*if(!intersections.empty()) {

				std::sort(intersections.begin(), intersections.end(), [cam](Intersection& v1, Intersection& v2){
					return v1.pos().distance(cam.pos()) < v2.pos().distance(cam.pos());
				});

				auto& intersection = intersections[0];

				int scalar = 0x8f + (1 - intersection.normal().dotProduct(dir)) * 0x8f;
				auto col = intersection.color() * sf::Color(scalar, scalar, scalar, 0xff);
				image->setPixel(x, y, col);

			}*/
		}
	}

}