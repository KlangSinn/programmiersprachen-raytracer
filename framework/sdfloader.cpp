//													 SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#include "sdfloader.h"

SDFLoader::SDFLoader() {}
SDFLoader::~SDFLoader() {}

std::vector<Material*> SDFLoader::getMaterials() {
	return materials_;
}
std::vector<Shape*> SDFLoader::getShapes() {
	return shapes_;
}
Camera SDFLoader::getCamera() {
	return camera_;
}

void SDFLoader::readFile(std::string file) {
	std::ifstream ifs(file);
	char line[256];
	std::cout << "Start reading sdf file ..." << std::endl;
	if (ifs.is_open()) {

		// if file was found read line per line and split it into separated words
		// parse words so that different objects will be created
		// go through separated words and create objects

		while (ifs.good()) {
			ifs.getline(line, 256);
			std::cout << line << std::endl; 
			std::vector<std::string> words = splitLine(line);
			int i = 0;
			while (i < words.size()) {

				// DEFINE // // // // // // // // // // // // // // // // // // // //
				if (words[i].compare("define") == 0) {

					// MATERIAL // // // // // // // // // // // // // // // // // //
					if (words[i + 1].compare("material") == 0) {
						std::string name = words[i + 2];
						Color ka = Color(
							std::stof(words[i + 3]), 
							std::stof(words[i + 4]), 
							std::stof(words[i + 5])
						);
						Color kd = Color(
							std::stof(words[i + 6]),
							std::stof(words[i + 7]),
							std::stof(words[i + 8])
						);
						Color ks = Color(
							std::stof(words[i + 9]),
							std::stof(words[i + 10]),
							std::stof(words[i + 11])
						);
						float m = std::stof(words[i + 12]);
						Material *matti = new Material(name, ka, kd, ks, m);
						materials_.push_back(dynamic_cast<Material*>(matti));
						i = i + 13; 

					// SHAPE // // // // // // // // // // // // // // // // // //
					} else if (words[i + 1].compare("shape") == 0) {

						// SPHERE // // // // // // // // // // // // // // // //
						if (words[i + 2].compare("sphere") == 0) {
							std::string name = words[i + 3];
							glm::vec3 center = glm::vec3(
								std::stof(words[i + 4]),
								std::stof(words[i + 5]),
								std::stof(words[i + 6])
								);
							double radius = std::stod(words[i + 7]);
							int found_at = -1;
							for (int j = 0; j < materials_.size() && found_at == -1; ++j) {
								if (materials_.at(j)->getName().compare(words[i + 8]) == 0)
									found_at = j;
							}
							Material material;
							if (found_at == -1) {
								material = Material();
								std::cout << "No material given or not found. Name of the material: " << words[i + 8] << std::endl;
							}
							else {
								material = *materials_.at(found_at);
							}
							Sphere *uschi = new Sphere(name, center, radius, material);
							shapes_.push_back(dynamic_cast<Sphere*>(uschi));
							i = i + 9;
							
						// UNKOWN SHAPE // // // // // // // // // // // // //
						} else {
							std::cout << "Error (in shape) parsing file" << std::endl;
						}

					// CAMERA // // // // // // // // // // // // // // // //
					} else if (words[i + 1].compare("camera") == 0) {
						std::string name = words[i + 2];
						double opening_angle = std::stod(words[i + 3]);
						camera_.name = name;
						camera_.opening_angle = opening_angle;
						i = i + 4;

					// DEFINE PARAMETERS ARE MISSING // // // // // // // //
					} else {
						std::cout << "Error parsing file. Define parameters are missing." << std::endl;
					}
				} else {
					i++;
				}
			}
		}
	} else {
		std::cout << "Error opening file" << std::endl;
	}
	std::cout << "finished reading sdf file ...\n" << std::endl;
}


std::vector<std::string> SDFLoader::splitLine(std::string line) {
	std::vector<std::string> words;
	std::stringstream ssin(line);
	while (ssin.good()){
		std::string word;
		ssin >> word;
		words.push_back(word);
	}	
	return words;
}

