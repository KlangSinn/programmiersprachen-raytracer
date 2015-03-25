//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#include "plane.h"
#include <ostream>
#include <cmath>
#include <algorithm>

Plane::Plane() {
	name_ = "";
	normal_ = glm::vec3();
	d_ = 0.0;
	material_ = Material();
}
Plane::Plane(std::string name, glm::vec3 normal, double d, Material material) : name_{ name }, normal_{ normal }, d_{ d }, material_{ material } {}
Plane::~Plane() {}

// // // // // // // // // // // // // // // // // // // // // // 

double Plane::intersect(Ray ray) {

	// two vectors are orthogonal if their dot product is zero
	// so if ray and normal are orthogonal, the plane and the ray are parallel!
	if (glm::dot(normal_, ray.direction) != 0) {

		// compare two equations and find d from ray: 
		//		plane: ax + by + cz = d where abc is the normal and d the constant of the plane
		//		normal: 0,1,0 would be a horizontal plane, d describes the distance to the origin (ex.: y = -10 = d)
		//		ray:	p1 = p0 + d * dir
		return (d_ - glm::dot(normal_, ray.origin)) / glm::dot(normal_, ray.direction);
	} else {

		// ray and plane are parallel (zero or endless solutions)
		return -1;
	}
}

// // // // // // // // // // // // // // // // // // // // // // 

// GETTER
std::string Plane::getName() {
	return name_;
}
Material Plane::getMaterial() const {
	return material_;
}
glm::vec3 Plane::getNormalAt(glm::vec3 point) const {
	return normal_;
}
double Plane::getD() {
	return d_;
}

// SETTER
void Plane::setName(std::string name) {
	name_ = name;
}
void Plane::setD(double d) {
	d_ = d;
}
void Plane::setMaterial(Material material) {
	material_ = material;
}