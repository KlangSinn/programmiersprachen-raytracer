#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.h"
#include "ray.h"

class Shape {
public:
	Shape();

	virtual std::string getName() { return "Britta"; };
	virtual double intersect(Ray ray) { return 0.0; }
	virtual Material getMaterial() { return Material();  }
};

#endif