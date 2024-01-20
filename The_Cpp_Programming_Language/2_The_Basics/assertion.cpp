#include <iostream>
using namespace std;

int main(){
  const int a =5;
  //note : static_assert always expects a constant expression
  static_assert(a>10,"Hurrah !! An assertion has been hit");
  cout<<"Happy Coding!!";

  return 0;
}
