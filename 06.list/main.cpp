#include <iostream>
#include <list>

int main() {
    std::list<int> list1 = {1, 2, 3};
    std::list<int> list2 = {4, 5, 6};

    std::cout << "交换前：" << std::endl;
    std::cout << "list1: ";
    for (const auto& num : list1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "list2: ";
    for (const auto& num : list2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    list1.swap(list2); // 交换两个列表的内容

    std::cout << "交换后：" << std::endl;
    std::cout << "list1: ";
    for (const auto& num : list1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "list2: ";
    for (const auto& num : list2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
