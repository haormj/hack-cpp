#include <iostream>
#include <vector>
#include <string>

class People {

public:
	People(const People& p) : name(p.name), age(p.age) {
		std::cout << "invoke copy constructor " << name << "," << age << std::endl;
	}
	People(std::string name, int age) : name(name), age(age) {
		std::cout << "invoke constructor " << name << "," << age << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& os, const People& p) {
		os << "name:" << p.name << ",age:" << p.age;
		return os;
	}
private:
	std::string name;
	int age;
};

int main() {
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (auto i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}

	std::vector<People> p;
	std::cout << "current capacity: " << p.capacity() << std::endl;
	p.emplace_back("haormj", 29);
	std::cout << "current capacity: " << p.capacity() << std::endl;

	p.push_back(People("xx", 10));
	std::cout << "current capacity: " << p.capacity() << std::endl;

	for (auto i = p.begin(); i != p.end(); i++) {
		std::cout << *i << std::endl;
	}

	return 0;
}