#include <iostream>
#include "person.pb.h"
#include <string>
#include <google/protobuf/text_format.h>
#include <fstream>
#include <sstream>

int main() {

	Person p;
	p.set_name("haormj");
	p.set_age(29);

	std::string data;
	p.SerializeToString(&data);

	Person p2;
	p2.ParseFromString(data);

	std::cout << p2.name() << "," << p2.age() << std::endl;

	std::fstream f("person.prototxt");
	std::stringstream buff;
	if (f.is_open()) {
		buff << f.rdbuf();
		f.close();
	} else {
		std::cout << "file open failed" << std::endl;
	}

	Person p3;
    if (google::protobuf::TextFormat::ParseFromString(buff.str(), &p3)) {
		std::cout << p3.name() << "," << p3.age() << std::endl;
	} else {
		std::cout << "反序列化失败" << std::endl;
	}


	return 0;
}