#include <iostream>
using namespace std;

// if we are storing the return value of a function in a constexpr,
// then the function should also be declared as constexpr
constexpr int square(int var) { return var * var; }

int main() {
  const int num = 5;
  cout << "value of num is : " << num << "\n";
  constexpr int res = square(num);
  cout << "Value of square(num) is : " << res << "\n";
  return 0;
}
