//
// Created by lunar on 06/10/18.
//

#include "Scene.hpp"

#include <algorithm>
#include <atomic>
#include <future>
#include <thread>

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

	const unsigned int sizeX = image->getSize().x;
	const unsigned int sizeY = image->getSize().y;
	const float dX = 1.0f/sizeX;
	const float dY = 1.0f/sizeY;

	const unsigned long imageSize = sizeX * sizeY;
	auto* imageArr = new unsigned int[imageSize];

	std::vector<std::future<void>> threads;
	std::atomic<unsigned long> workingIndex = 0;
	int hwThreads = std::thread::hardware_concurrency();

	if(hwThreads == 0)
		hwThreads = 1;

	for (int i = 0; i < hwThreads; ++i) {
		threads.emplace_back(std::async([this, &workingIndex, sizeX, sizeY, dX, dY, imageSize, imageArr, &cam]() -> void {
			for(;;) {

				unsigned long index = workingIndex++;
				if(index > imageSize)
					break;

				const int x = index % sizeX;
				const int y = index / sizeX;

				Vec3f dir((dX*(x-sizeX*.5))*2, (-dY*(y-sizeY*.5))*2, 1);

				Ray r(cam.pos(), dir);

				auto ret = r.trace(*this);
				if(ret) {
					//Might be able to mutate the image directly, if it's thread-safe in this case
					imageArr[index] = static_cast<unsigned int>(*ret);
				}

			}
		}));
	}

	for (auto& f : threads) {
		f.get();
	}

	for (unsigned long i = 0; i < imageSize; ++i) {
		const int x = i % sizeX;
		const int y = i / sizeX;
		image->setPixel(x, y, sf::Color(imageArr[i]));
	}

	delete[] imageArr;

}