//													 SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_PLANE_HPP
#define BUW_PLANE_HPP

#include <iosfwd>

#include <color.hpp>
#include <glm/glm.hpp>

#include "shape.h"

class Plane : public Shape {
public:
	Plane();
	Plane(std::string name, glm::vec3 normal, double d, Material material);
	~Plane();

	/* virtual */ std::string getName();
	/* virtual */ Material getMaterial() const;
	/* virtual */ double intersect(Ray ray);
	/* virtual */ glm::vec3 getNormalAt(glm::vec3 point) const;

	bool isInPlane(glm::vec3 point);

	double getD();

	void setName(std::string name);
	void setD(double d);
	void setMaterial(Material material);

private:
	std::string name_;
	glm::vec3 normal_;
	double d_;
	Material material_;
};

#endif // BUW_PLANE_HPP
