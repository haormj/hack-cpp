#include <iostream>
#include <deque>

class Test {

public:
	Test(int x, int y) : x(x), y(y) {
		std::cout << "test construct" << std::endl;
	}

	Test(const Test& t) {
		std::cout << "copy construct" << std::endl;
		x = t.x;
		y = t.y;
	}

	friend std::ostream& operator<<(std::ostream& os, const Test& t) {
		os << t.x << "," << t.y;
		return os;
	}

private:
	int x;
	int y;
};

int main() {
	std::deque<Test> queue;
	Test t(1, 2);
	Test t2(2, 3);
	// queue.push_back(t);
	queue.emplace_back(t2);
	// queue.emplace_back(3, 4);

	std::cout << t << std::endl;
	std::cout << t2 << std::endl;
	std::cout << &t2 << std::endl;

	for (auto v = queue.begin(); v != queue.end(); v++) {
		std::cout << *v << std::endl;
		std::cout << &*v << std::endl;
	}

	return 0;
}