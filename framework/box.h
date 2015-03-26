//													 SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include <iosfwd>

#include <color.hpp>
#include <glm/glm.hpp>

#include "shape.h"
#include "plane.h"

class Box : public Shape {
public:
	Box();
	Box(std::string name, glm::vec3 pmin, glm::vec3 pmax, Material material);
	~Box();

	/* virtual */ std::string getName();
	/* virtual */ Material getMaterial() const;
	/* virtual */ double intersect(Ray ray);
	/* virtual */ glm::vec3 getNormalAt(glm::vec3 point) const;

	glm::vec3 getPMin();
	glm::vec3 getPMax();

	void setName(std::string name);
	void setPMin(glm::vec3 pmin);
	void setPMax(glm::vec3 pmax);
	void setMaterial(Material material);

private:
	std::string name_;
	glm::vec3 pmin_;
	glm::vec3 pmax_;
	Material material_;
};

#endif // BUW_BOX_HPP