#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <vector>

struct People {
	std::string name;
	int age;

	friend void from_json(const nlohmann::json& j, People& p) {
		j.at("name").get_to(p.name);
		j.at("age").get_to(p.age);
	}

	friend void to_json(nlohmann::json& j, const People& p) {
		j = nlohmann::json{
			{"name", p.name},
			{"age", p.age}
		};
	}

	friend std::ostream& operator<<(std::ostream& os, const People& p) {
		os << "name:" << p.name << ",age:" << p.age;
		return os;
	}
};

int main() {
	People p = nlohmann::json::parse(R"(
	{
		"name": "haormj",
		"age": 29
	}
	)");

	std::cout << p << std::endl;

	std::vector<People> p2 = nlohmann::json::parse(R"(
	[
		{
			"name": "haormj",
			"age": 29
		},
		{
			"name": "haormj2",
			"age": 30
		}
	]
	)");
	for (auto i = 0; i < p2.size(); i++) {
		std::cout << p2[i] << std::endl;
	}

	nlohmann::json j2 = p2;
	std::cout << j2 << std::endl;

	return 0;
}