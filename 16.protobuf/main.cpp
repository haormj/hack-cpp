#include <iostream>
#include "person.pb.h"
#include <string>

int main() {
	Person p;
	p.set_name("haormj");
	p.set_age(29);

	std::string data;
	p.SerializeToString(&data);

	Person p2;
	p2.ParseFromString(data);

	std::cout << p2.name() << "," << p2.age() << std::endl;

	return 0;
}