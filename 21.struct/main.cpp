#include <iostream>
#include <string>

struct Person {
  std::string Name;
  int age;
};

int main() {
  Person p{"hao", 11};
  std::cout << p.Name << std::endl;
}