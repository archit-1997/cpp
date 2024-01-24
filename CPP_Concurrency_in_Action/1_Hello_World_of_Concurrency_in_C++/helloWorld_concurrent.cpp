#include <iostream>
#include <thread>

void hello_world() { std::cout << "Hello World!!\n"; }

int main() {
  std::thread t(hello_world);
  t.join();
  return 0;
}
