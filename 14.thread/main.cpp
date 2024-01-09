#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int main() {
	int n = 100;
	std::mutex mtx;

	auto fn = [&]() {
		while (true) {
			{
				std::lock_guard<std::mutex> lock(mtx);
				if (n <= 0) {
					break;
				}
				std::cout << std::this_thread::get_id() << ": " << n << std::endl;
				n--;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	};

	std::thread t1(fn);
	std::thread t2(fn);

	t1.join();
	t2.join();

	return 0;
}