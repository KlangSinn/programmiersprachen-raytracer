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
#include "plane.h"
#include "box.h"
#include "camera.h"
#include "light.h"

class SDFLoader {
public:
	SDFLoader();
	~SDFLoader();

	void readFile(std::string file);
	std::vector<Material*> getMaterials();
	std::vector<Shape*> getShapes();
	std::vector<Light*> getLights();
	Camera getCamera();
	Material findMaterialByName(std::string name);

	static std::vector<std::string> splitLine(std::string line);

private:
	std::vector<Material*> materials_;
	std::vector<Shape*> shapes_;
	std::vector<Light*> lights_;
	Camera camera_;
};

#endif // BUW_SDF_LOADER_HPP
