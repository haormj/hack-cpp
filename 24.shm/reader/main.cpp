#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
  const char* shm_name = "/my_shared_memory";
  const size_t SIZE = 4096;

  // 打开共享内存对象
  int shm_fd = shm_open(shm_name, O_RDONLY, 0666);
  if (shm_fd == -1) {
    std::cerr << "Failed to open shared memory object" << std::endl;
    return 1;
  }

  // 映射共享内存
  void* ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  if (ptr == MAP_FAILED) {
    std::cerr << "Failed to map shared memory" << std::endl;
    return 1;
  }

  // 读取共享内存的数据
  std::cout << "Message read from shared memory: " << static_cast<char*>(ptr)
            << std::endl;

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

  // 删除共享内存对象
  if (shm_unlink(shm_name) == -1) {
    std::cerr << "Failed to unlink shared memory object" << std::endl;
    return 1;
  }

  return 0;
}
