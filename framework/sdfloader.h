//													SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef BUW_SDF_LOADER_HPP
#define BUW_SDF_LOADER_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include "material.h"

class SDFLoader {
public:
	SDFLoader();
	~SDFLoader();

	static std::vector<Material> readFile(std::string file);
	static std::vector<std::string> splitLine(std::string line);

};

#endif // BUW_SDF_LOADER_HPP
