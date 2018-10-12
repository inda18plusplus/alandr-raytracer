//
// Created by lunar on 06/10/18.
//

#ifndef RAYTRACING_SCENE_HPP
#define RAYTRACING_SCENE_HPP

#include <memory>
#include <vector>

#include <SFML/Graphics/Image.hpp>

#include "RenderObject.hpp"
#include "Camera.hpp"
#include "Light.hpp"

class Scene {

	std::vector<std::shared_ptr<RenderObject>> _objects;
	std::vector<std::shared_ptr<Light>> _lights;

public:
	Scene() = default;

	std::shared_ptr<sf::Image> render(unsigned int width, unsigned int height, const Camera &cam);
	void renderTo(std::shared_ptr<sf::Image> image, const Camera &cam);

	void addObject(std::shared_ptr<RenderObject> object) { _objects.push_back(object); }
	std::shared_ptr<RenderObject> transferObject(RenderObject* obj);

	void addLight(std::shared_ptr<Light> light) { _lights.push_back(light); }
	std::shared_ptr<Light> transferLight(Light* light);

	const auto& getObjects() const { return _objects; }
	const auto& getLights() const { return _lights; }

};


#endif //RAYTRACING_SCENE_HPP
