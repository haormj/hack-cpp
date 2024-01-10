#include <iostream>
#include "yaml-cpp/yaml.h"

int main() {
	YAML::Node config = YAML::LoadFile("config.yaml");

	std::cout << (config["person"]["age"].as<int>() == 29) << std::endl;
	return 0;
}