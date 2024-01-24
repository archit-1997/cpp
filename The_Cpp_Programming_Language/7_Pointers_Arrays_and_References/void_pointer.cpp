#include <iostream>
using namespace std;

void void_pointer_func(int *p) {
  cout << "Inside void_pointer_func\n";
  cout << "Value of *p is : " << *p << "\n";
  void *void_p = p;
  // cout << *void_p << "\n";
  double *double_p = static_cast<double *>(
      void_p); // unsafe operation : hint : look at the output of *double_p,
               // it's not same as output of *p
  cout << "Printing the value of double_p " << *double_p << "\n";
  cout << "Outside void_pointer_func\n";
}

int main() {
  // In low level, we need to store or pass along an address of a memory
  // location
  // without actually knowing what type of object is stored there. A void∗ is
  // used for that. You can read void∗ as ‘‘pointer to an object of unknown
  // type.’’

  // a pointer to any type of object can be assigned to void*
  // Exception :
  // 1. pointer to function
  // 2. pointer to member
  // The above cannot be assigned to void*

  // void* can be assigned to another void*
  // void* can be converted (explicitly) to another type

  // other operations throw compile time error because the compiler doesn't know
  // to what type of object is void* pointing to

  // Primary use of void*
  // 1.primary use of void* is for passing pointers to functions that are not
  // allowed to make assumptions about the type of object 2.returning untyped
  // objects from functions. Now to use such objects, we must use explicit type
  // conversion.

  // Functions using void* are used at the lowest level of the system, typically
  // where real hardware resources are manipulated
  // eg : return type of malloc is void*

  int a = 5;
  int *p = &a;

  void_pointer_func(p);

  cout << a << "\n";
  return 0;
}
