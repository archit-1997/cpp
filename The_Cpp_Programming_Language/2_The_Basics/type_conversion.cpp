#include <iostream>
using namespace std;

int main(){

  double d=3.123;
  cout<<"Value of d is : "<<d<<"\n";
  int i=5;
  cout<<"Value of i is : "<<i<<"\n";
  d=d+i; 
  cout<<"Value of d when I've done d=d+i is : "<<d<<"\n";
  i=d*i; //this value has been truncated
  cout<<"Value of i when I've done i=d*i is : "<<i<<"\n";


  return 0;

}
