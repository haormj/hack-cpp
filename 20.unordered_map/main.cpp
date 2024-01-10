#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	std::unordered_map<std::string, int> m;
	m["haormj"] = 1;
	m["haormj2"] = 2;

	for (const auto& pair : m) {
		std::cout << pair.first << ":" << pair.second << std::endl;
	}

	m.erase("haormj");
	auto it = m.find("haormj");
	if (it == m.end()) {
		std::cout << "can not find key" << std::endl;
	}

	return 0;
}