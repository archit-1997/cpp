#include <iostream>
using namespace std;

int main() {
  int p = 5;
  int *ptr_p = &p;
  // double pointer declaration
  int **ptr_ptr_p = &ptr_p;
  cout << "Value of p is : " << p << "\n";
  // printing the memory address of p
  cout << "Value of  &p is : " << (&p) << "\n";
  // printing the value stored in the poiner
  cout << "Value of *ptr_p is : " << (*ptr_p) << "\n";
  // printing the address of the pointer
  cout << "Value of &ptr_p is : " << (&ptr_p) << "\n";
  // dereferencing the value of teh variable p from the pointers memory address
  cout << "Value of **ptr_ptr_p is : " << (**ptr_ptr_p) << "\n";
  return 0;
}
