#include <iostream>

struct RAIIPtr {
  int *ptr_;
  RAIIPtr(int *p) : ptr_(p) {}
  ~RAIIPtr() { delete[] ptr_; };
  // deleting the copy constructor
  RAIIPtr(const RAIIPtr &rhs) = delete;
  // deleting the copy assignment constructor
  RAIIPtr &operator=(const RAIIPtr &rhs) = delete;
};

int main() {

  try {
    RAIIPtr arr = new int[4];
    throw std::runtime_error("Runtime Error Example\n");
  } catch (const std::exception &ex) {
    std::cout << "Caught an exception : " << ex.what() << "\n";
  }

  return 0;
}
