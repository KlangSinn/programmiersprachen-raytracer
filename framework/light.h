#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <string>
#include <glm/glm.hpp>
#include "color.hpp"

class Light {
public:
	Light();
	Light(std::string name, glm::vec3 position, Color la, Color ld);

	std::string getName();
	glm::vec3 getPosition();
	Color getLA();
	Color getLD();

private:
	std::string name_;
	glm::vec3 position_;
	Color la_;
	Color ld_;
};

#endif