#include <iostream>
#include <string>

int main() {
	std::string s = "hello world";
	std::cout << s.length() << std::endl;

	std::string s2 = R"(this is raw string
something 原始字符串
end)";
	std::cout << s2 << std::endl;

	std::string si = "1";
	auto i = std::stoi(si);
	std::cout << i << std::endl;
	
	auto s3 = std::to_string(i);
	std::cout << s3 << std::endl;

	std::string s4 = "你好";
	std::string s5 = "世界";
	std::string s6 = s4 + s5;
	std::cout << s6 << std::endl;
	std::cout << &s4 << " " << &s5 << " " << &s6 << std::endl;

	return 0;
}