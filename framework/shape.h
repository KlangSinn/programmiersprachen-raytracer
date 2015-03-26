#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.h"
#include "ray.h"

class Shape {
public:
	Shape();

	virtual std::string getName() { return " "; };
	virtual double intersect(Ray ray) { return 0.0; }
	virtual Material getMaterial() const { return Material();  }
	virtual glm::vec3 getNormalAt(glm::vec3 point) const { return glm::vec3(); }
};

#endif