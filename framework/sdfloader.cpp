//													 SASCHA DOBSCHAL
// // // // // // // // // // // // // // // // // // // // // // //

#include "sdfloader.h"

SDFLoader::SDFLoader() {

}
SDFLoader::~SDFLoader() { }

// TODO: instead of material return gernal scene objects
std::vector<Material> SDFLoader::readFile(std::string file) {
	std::vector<Material> materials;
	std::ifstream ifs(file);
	char line[256];
	std::cout << "Start reading sdf file ..." << std::endl;
	if (ifs.is_open()) {

		// if file was found read line per line and split it into separated words
		// parse words so that different objects will be created
		// go through separated words and create objects

		while (ifs.good()) {
			ifs.getline(line, 256);
			std::vector<std::string> words = splitLine(line);
			int i = 0;
			while (i < words.size()) {
				if (words[i].compare("define") == 0) {
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
						materials.push_back(Material(name, ka, kd, ks, m));
						i = i + 13; 
					} else {
						std::cout << "Error parsing file" << std::endl;
					}
				} else {
					i++;
				}
			}
		}
	} else {
		std::cout << "Error opening file" << std::endl;
	}	
	return materials;
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

