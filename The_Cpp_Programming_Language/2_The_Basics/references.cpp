#include <iostream>
using namespace std;

int main() {

  int a = 5;
  int &ref_a = a;
  cout << "value of a is " << a << "\n";
  cout << "Value of ref_a is :  " << ref_a << "\n";

  // changing the value stored in ref_a
  ref_a = 1;
  cout << "Printing the value after changing the value stored in ref_a = 1"
       << "\n";
  cout << "value of a is " << a << "\n";
  cout << "Value of ref_a is :  " << ref_a << "\n";

  return 0;
}
