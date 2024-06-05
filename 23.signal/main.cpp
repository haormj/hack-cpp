#include <chrono>
#include <csignal>
#include <iostream>
#include <thread>

// 定义信号处理函数
void signalHandler(int signum) {
  std::cout << "Interrupt signal (" << signum << ") received.\n";

  int i = 0;
  for (i = 0; i < 10; i++) {
    std::cout << "Sleeping..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  std::cout << "Exiting..." << std::endl;
}

int main() {
  // 注册信号 SIGINT 和处理函数
  signal(SIGINT, signalHandler);
  signal(SIGTERM, signalHandler);
  signal(SIGABRT, signalHandler);
  signal(SIGSEGV, signalHandler);

  while (1) {
    std::cout << "Running..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "send signal" << std::endl;
    raise(SIGINT);
  }

  return 0;
}