#include <iostream>
#include <thread>

int main() {
  std::thread hello_thread([] { std::cout << "Hello World!!\n"; });
  hello_thread.join();
  return 0;
}
