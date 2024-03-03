#include <iostream>

class ZeroVector {
private:
  std::vector<int> vec_;

public:
  // copy constructor
  Vector(const ZeroVector &rhs) = default;
  // move contructor
  Vector(ZeroVector &&rhs) = default;
  // copy assignment operator
  ZeroVector &operator=(const ZeroVector &rhs) = default;
  // move assignment operator
  ZeroVector &operator=(ZeroVector &&rhs) = default;
  // destructor
  ~Vector() = default;
  // friend swap declaration
};

int main() {

  std::cout << "True Zero Vector\n";

  return 0;
}
