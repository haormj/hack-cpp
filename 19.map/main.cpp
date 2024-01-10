#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main() {
	std::map<std::string, int> m;
	m["haormj"] = 1;
	m["haormj2"] = 2;

	std::cout << m.size() << std::endl;
	
	for (const auto& pair : m) {
		std::cout << pair.first << ":" << pair.second << std::endl;
	}

	auto it = m.find("haormj");
	if (it != m.end()) {
		std::cout << "find " << it->first << ":" << it->second << std::endl;
	}

	m.erase("haormj2");

	std::for_each(m.cbegin(), m.cend(), [](const std::pair<std::string, int>& pair) {
		std::cout << pair.first << ":" << pair.second << std::endl;
	});

	return 0;
}