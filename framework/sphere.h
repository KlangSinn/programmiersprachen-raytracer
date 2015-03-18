//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include <iosfwd>

#include <color.hpp>
#include <glm/glm.hpp >
#include "ray.h"

class Sphere {
public:
	Sphere();
	Sphere(glm::vec3 center, double radius);
	~Sphere();

	glm::vec3 getCenter();
	double getRadius();

	void setCenter(glm::vec3 center);
	void setRadius(double radius);

	double intersect(Ray ray);
private:
	glm::vec3 center_;
	double radius_;
};

#endif // BUW_SPHERE_HPP
