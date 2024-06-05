#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
  const char* shm_name = "/my_shared_memory";
  const size_t SIZE = 4096;

  // 创建共享内存对象
  int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
  if (shm_fd == -1) {
    std::cerr << "Failed to create shared memory object" << std::endl;
    return 1;
  }

  // 配置共享内存大小
  if (ftruncate(shm_fd, SIZE) == -1) {
    std::cerr << "Failed to set shared memory size" << std::endl;
    return 1;
  }

  // 映射共享内存
  void* ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (ptr == MAP_FAILED) {
    std::cerr << "Failed to map shared memory" << std::endl;
    return 1;
  }

  // 写入数据到共享内存
  const char* message = "Hello from writer";
  memcpy(ptr, message, strlen(message) + 1);

  std::cout << "Message written to shared memory: " << message << std::endl;

  // 解除映射
  if (munmap(ptr, SIZE) == -1) {
    std::cerr << "Failed to unmap shared memory" << std::endl;
    return 1;
  }

  // 关闭共享内存对象
  if (close(shm_fd) == -1) {
    std::cerr << "Failed to close shared memory object" << std::endl;
    return 1;
  }

  return 0;
}
