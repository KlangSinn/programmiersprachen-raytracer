//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP

#include <iosfwd>
#include <string>
#include <sstream>
#include <vector>

#include "color.hpp"

class Material {
public:
	Material();
	Material(std::string name, Color ka, Color kd, Color ks, float m);
	~Material();

	std::string getName();
	Color getKA();
	Color getKD();
	Color getKS();
	float getM();

private:
	std::string name_;
	Color ka_;
	Color kd_;
	Color ks_;
	float m_;

};

std::ostream& operator<<(std::ostream& os, Material& m);

#endif // BUW_MATERIAL_HPP
