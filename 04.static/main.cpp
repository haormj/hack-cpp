#include <iostream>

class Test {
    public:
        Test() {
            std::cout << "调用构造函数" << std::endl;
        }
        ~Test() {
            std::cout << "调用析构函数" << std::endl;
        }
};

static Test Tests() {
    static Test t;
    return t;
}

int main() {
    Tests();
    Tests();
    return 0;
}