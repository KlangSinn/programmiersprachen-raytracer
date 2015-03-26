//													 SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include <iosfwd>

#include <color.hpp>
#include <glm/glm.hpp>

#include "shape.h"

class Box : public Shape {
public:
	Box();
	Box(std::string name, glm::vec3 p1, glm::vec3 p2, Material material);
	~Box();

	/* virtual */ std::string getName();
	/* virtual */ Material getMaterial() const;
	/* virtual */ double intersect(Ray ray);
	/* virtual */ glm::vec3 getNormalAt(glm::vec3 point) const;

	glm::vec3 getP1();
	glm::vec3 getP2();

	void setName(std::string name);
	void setP1(glm::vec3 p1);
	void setP2(glm::vec3 p2);
	void setMaterial(Material material);

private:
	std::string name_;
	glm::vec3 p1_;
	glm::vec3 p2_;
	Material material_;
};

#endif // BUW_BOX_HPP