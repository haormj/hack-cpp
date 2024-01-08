#include <iostream>
#include <regex>

int main() {
	std::regex pattern(R"(\s)");
	std::string s = " ";

	std::cout << std::regex_match(s, pattern) << std::endl;	

	return 0;
}