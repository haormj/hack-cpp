#include <iostream>


int main() {
#if (OS==linux && ARCH==amd64)
	std::cout << "os: linux, arch: amd64" << std::endl;
#else
	std::cout << "don't support in current os and arch" << std::endl;
#endif

#if 0
	std::cout << "只有打开，这段代码才会执行" << std::endl;
#endif

	return 0;
}