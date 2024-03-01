#include <iostream>

void fun(std::vector<int> &byRef) { std::cout << "This is &byRef\n"; }

void fun(const std::vector<int> &byConstRef) {
  std::cout << "This is &byConstRef\n";
}

//&& triggers move semantics
void fun(std::vector<int> &&byMoveRef) {
  std::cout << "This is &&moveRef\n";
}

int main() {

  std::vector<int> a{1, 2, 3};
  const std::vector<int> b{4, 5, 6};

  fun(a);         // pass an lvalue
  fun(b);         // pass a const lvalue
  fun({7, 8, 9}); // pass a temporary object

  // passing an lvalue by static cast : Triggeting an rvalue overload
  fun(static_cast<std::vector<int> &&>(a));

  // NOTE : static_cast<std::vector<int> && has type-casted a normal vector
  // so that the memory allocated can be captured by triggering move semantics.
  // Now, because writing such a big word is so tedious, there's a small
  // abbreviation for it : std::move()

  // this is also move semantics
  fun(std::move(a));

  return 0;
}
