#include <iostream>

int main() {
	auto fn = [](int x) {
		std::cout << x * x << std::endl;
	};
	fn(3);


	auto n = 10;
	// 按值捕获变量，就是类似函数的值传递，会直接拷贝一份
	auto fn2 = [=](int x) {
		std::cout << n * x << std::endl;
	};
	fn2(3);

	auto n2 = 11;
	// 按引用捕获变量，该变量可以在lambda内部改变
	auto fn3 = [&](int x) {
		std::cout << n2 * x << std::endl;
		n2 = 12;
	};
	fn3(3);
	std::cout << n2 << std::endl;

	// 有返回值的lambda
	auto fn4 = [](int x) -> int {
		return x * x;
	};
	std::cout << fn4(3) << std::endl;

	return 0;
}