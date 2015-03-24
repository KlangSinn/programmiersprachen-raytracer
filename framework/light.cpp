#include "light.h"

Light::Light() {
	name_ = "unknown";
	position_ = glm::vec3();
	la_ = Color();
	ld_ = Color();
}
Light::Light(std::string name, glm::vec3 position, Color la, Color ld) : name_{ name }, position_{ position }, la_{ la }, ld_{ ld } {}

std::string Light::getName() {
	return name_;
}
glm::vec3 Light::getPosition() {
	return position_;
}
Color Light::getLA() {
	return la_;
}
Color Light::getLD() {
	return ld_;
}