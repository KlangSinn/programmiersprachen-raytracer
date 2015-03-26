//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#include "box.h"
#include <ostream>
#include <cmath>
#include <algorithm>

Box::Box() {
	name_ = "";
	p1_ = glm::vec3();
	p2_ = glm::vec3();
	material_ = Material();
}
Box::Box(std::string name, glm::vec3 p1, glm::vec3 p2, Material material) : name_{ name }, p1_{ p1 }, p2_{ p2 }, material_{ material } {}
Box::~Box() {}

// // // // // // // // // // // // // // // // // // // // // // 

double Box::intersect(Ray ray) {
	return -1;
}

// // // // // // // // // // // // // // // // // // // // // // 

// GETTER
std::string Box::getName() {
	return name_;
}
Material Box::getMaterial() const {
	return material_;
}
glm::vec3 Box::getNormalAt(glm::vec3 point) const {
	if (point.x == p1_.x)
		return glm::vec3(-1, 0, 0);
	else if (point.x == p2_.x)
		return glm::vec3(1, 0, 0);
	else if (point.y == p1_.y)
		return glm::vec3(0, -1, 0);
	else if (point.y == p2_.y)
		return glm::vec3(0, 1, 0);
	else if (point.z == p1_.z)
		return glm::vec3(0, 0, 1);
	else if (point.z == p2_.z)
		return glm::vec3(0, 0, -1);
	else
		return glm::vec3();
}
glm::vec3 Box::getP1() {
	return p1_;
}
glm::vec3 Box::getP2() {
	return p2_;
}

// SETTER
void Box::setName(std::string name) {
	name_ = name;
}
void Box::setP1(glm::vec3 p1) {
	p1_ = p1;
}
void Box::setP2(glm::vec3 p2) {
	p2_ = p2;
}
void Box::setMaterial(Material material) {
	material_ = material;
}