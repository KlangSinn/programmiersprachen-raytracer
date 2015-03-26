//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include <iosfwd>

#include <color.hpp>
#include <glm/glm.hpp>

#include "shape.h"

class Sphere : public Shape {
public:
	Sphere();
	Sphere(std::string name, glm::vec3 center, double radius, Material material);
	~Sphere();

	/* virtual */ std::string getName();
	/* virtual */ Material getMaterial() const;
	/* virtual */ double intersect(Ray ray);
	/* virtual */ glm::vec3 getNormalAt(glm::vec3 point) const;

	glm::vec3 getCenter();
	double getRadius();
	
	void setName(std::string name);
	void setCenter(glm::vec3 center);
	void setRadius(double radius);
	void setMaterial(Material material);


private:
	std::string name_;
	glm::vec3 center_;
	double radius_;
	Material material_;
};

#endif // BUW_SPHERE_HPP
