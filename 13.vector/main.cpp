#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

	// 统计指定值在容器中出现的次数
	auto n1 = std::count(v.begin(), v.end(), 4);
	std::cout << "std::count: " << n1 << std::endl;

	auto n2 = std::count_if(v.cbegin(), v.cend(), [](const int& i) {
		return i > 2;
	});
	std::cout << "std::count_if: " << n2 << std::endl;

	std::sort(v.begin(), v.end(), [](int i, int j) {
		return i > j;
	});

	for (auto i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}

	for (const auto& i : v) {
		std::cout << i << std::endl;
	}

	std::for_each(v.cbegin(), v.cend(), [](const int& i){
		std::cout << i << std::endl;
	});

	std::vector<People> p;
	std::cout << "current capacity: " << p.capacity() << std::endl;
	p.emplace_back("haormj", 29);
	std::cout << "current capacity: " << p.capacity() << std::endl;

	p.push_back(People("xx", 10));
	std::cout << "current capacity: " << p.capacity() << std::endl;

	for (auto it = p.begin(); it != p.end(); it++) {
		std::cout << *it << std::endl;
	}

	return 0;
}