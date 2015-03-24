//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_SDF_LOADER_HPP
#define BUW_SDF_LOADER_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <glm/glm.hpp >
#include "material.h"
#include "shape.h"
#include "sphere.h"
#include "camera.h"

class SDFLoader {
public:
	SDFLoader();
	~SDFLoader();

	void readFile(std::string file);
	std::vector<Material*> getMaterials();
	std::vector<Shape*> getShapes();
	Camera getCamera();

	static std::vector<std::string> splitLine(std::string line);

private:
	std::vector<Material*> materials_;
	std::vector<Shape*> shapes_;
	Camera camera_;
};

#endif // BUW_SDF_LOADER_HPP
