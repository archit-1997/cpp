#include <iostream>

void fun(std::vector<int> &byRef) { std::cout << "This is &byRef\n"; }

void fun(const std::vector<int> &byConstRef) {
  std::cout << "This is &byConstRef\n";
}

int main() {

  std::vector<int> a{1, 2, 3};
  const std::vector<int> b{4, 5, 6};

  fun(a);         // pass an lvalue
  fun(b);         // pass a const lvalue
  fun({7, 8, 9}); // pass a temporary object

  return 0;
}
