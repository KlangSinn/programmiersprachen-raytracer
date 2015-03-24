//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#include "sphere.h"
#include <ostream>
#include <cmath>
#include <algorithm>

Sphere::Sphere() {
	name_ = "";
	center_ = glm::vec3(0.0, 0.0, 0.0);
	radius_ = 1.0;
	material_ = Material();
}
Sphere::Sphere(std::string name, glm::vec3 center, double radius, Material material) : name_{ name }, center_{ center }, radius_{ radius }, material_{ material } {}
Sphere::~Sphere() { }

std::string Sphere::getName() {
	return name_;
}
glm::vec3 Sphere::getCenter() {
	return center_;
}
double Sphere::getRadius() {
	return radius_;
}
Material Sphere::getMaterial() {
	return material_;
}

void Sphere::setName(std::string name) {
	name_ = name;
}
void Sphere::setCenter(glm::vec3 center) {
	center_ = center;
}
void Sphere::setRadius(double radius) {
	radius_ = radius;
}
void Sphere::setMaterial(Material material) {
	material_ = material;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // 

double Sphere::intersect(Ray ray) {

	// compute delta and handle cases
	float a = glm::dot(ray.direction, ray.direction); // a = d*d
	float b = 2.0f*glm::dot(ray.direction, ray.origin - center_); // b = 2d(o-C)
	float c = glm::dot(ray.origin - center_, ray.origin - center_) - pow(radius_, 2); // c = (o-C)^2-R^2

	//Calculate discriminant
	float delta = (b*b) - (4.0f*a*c);

	if (delta < 0) {

		// no intersection
		return -1;
	} else if (delta == 0) {

		// one intersection
		return (-1 * b) / (2 * a);
	} else {

		// two intersections
		double d1 = (-1 * b - sqrt(delta)) / (2 * a);
		double d2 = (-1 * b + sqrt(delta)) / (2 * a);
		return std::min(d1, d2);
	}
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // 