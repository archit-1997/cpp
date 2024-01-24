#include <iostream>
#include <thread>

int main() {
  // using lambda function
  std::thread hello_thread([] { std::cout << "Hello World!!\n"; });
  hello_thread.join();
  return 0;
}
