#include <iostream>

// function that takes lvalue reference
void foo(std::string &lvalueRef) { std::cout << "Inside lvalueRef\n"; }

// function that takes const lvalue reference
// this can take both lvalue and rvalue as parameters
void foo(const std::string &constLvalueRef) {
  std::cout << "Inside constLvalueRef\n";
}

// function that takes rvalue reference
void foo(std::string &&rvalueRef) { std::cout << "Inside rvalueRef\n"; }

// function that takes const rvalue reference
void foo(const std::string &&constRvalueRef) {
  std::cout << "Inside constRvalueRef\n";
}

int main() {

  std::cout << "Overload Resolution !!\n";
  std::string s1 = "Hello ";
  const std::string s2 = "Const Hello\n";
  // this cannot call rvalueRef and constRvalueRef because s is an lvalue.
  // this will prefer lvalueRef over constLvalueRef.
  foo(s1);
  // this cannot call lvalueRef,rvalueRef and constRvalueRef because s is an
  // const lvalue.
  // this will always call constLvalueRef.
  foo(s2);
  // this cannot call lvalueRef because this is an rvalue.
  // it will prefer rvalueRef over constLvalueRef and constRvalueRef.
  foo(s1 + "World !!");
  foo("World !!");
  // this cannot call lvalueRef because this is an rvalue ref.
  // it will prefer rvalueRef over constLvalueRef and constRvalueRef.
  foo(std::move(s1));
  // this cannot call lvalueRef and rvalueRef because this is an const rvalue
  // ref. it will prefer constRvalueRef over constLvalueRef .
  foo(std::move(s2));

  return 0;
}
