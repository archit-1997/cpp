#include <iostream>
#include <string>

struct CopyVector {

  int a, b;
};

int main() {

  int a = 2;
  int b = a; // this is always copied by default

  std::cout << "Printing a and b without changing the value of b\n";
  // how to demonstrate? We can print the memory addresses
  std::cout << a << " " << &a << "\n";
  std::cout << b << " " << &b << "\n";

  std::cout << "Printing a and b after changing the value of b\n";
  b = 3;
  std::cout << a << " " << &a << "\n";
  std::cout << b << " " << &b << "\n";

  // the same holds true for clases and vectors
  CopyVector v1{6, 7};
  CopyVector v2 = v1;

  std::cout << "Printing v1 and v2 without changing the value of struct "
               "members in v2\n";
  // NOTE : The memory addresses printed here would be different
  std::cout << v1.a << " " << &(v1.a) << " " << v1.b << " " << &(v1.b) << "\n";
  std::cout << v2.a << " " << &(v2.a) << " " << v2.b << " " << &(v2.b) << "\n";

  v2.a = 2;
  v2.b = 3;

  std::cout << "Printing v1 and v2 after changing the value of struct members "
               "in v2\n";
  std::cout << v1.a << " " << &(v1.a) << " " << v1.b << " " << &(v1.b) << "\n";
  std::cout << v2.a << " " << &(v2.a) << " " << v2.b << " " << &(v2.b) << "\n";

  // NOTE : We don't the objects when using pointers (except for this,
  // everywhere it's copy)

  CopyVector *pv1 = new CopyVector();
  pv1->a = 11;
  pv1->b = 22;

  std::cout
      << " Print the values and memory addresses of data members of pv1\n";
  std::cout << pv1->a << " " << &(pv1->a) << " " << pv1->b << " " << &(pv1->b)
            << "\n";

  CopyVector *pv2 = pv1;
  pv2->a = 44, pv2->b = 55;
  std::cout
      << " Print the values and memory addresses of data members of pv1\n";
  std::cout << pv1->a << " " << &(pv1->a) << " " << pv1->b << " " << &(pv1->b)
            << "\n";
  std::cout
      << " Print the values and memory addresses of data members of pv2\n";
  std::cout << pv2->a << " " << &(pv2->a) << " " << pv2->b << " " << &(pv2->b)
            << "\n";

  // NOTE : In the logs, both pv1->a and pv2->a will point to the same memory
  // address

  return 0;
}
