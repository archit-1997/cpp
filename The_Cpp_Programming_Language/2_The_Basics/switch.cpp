#include <iostream>
using namespace std;

int main(){
  cout<<"Enter a number\n";
  int num; cin>>num;
  switch(num){
    case 1 : 
    cout<<"The value of the number is 1\n";
    case 2 : 
    cout<<"The value of the number is 2\n";
    case 3 : 
    cout<<"The value of the number is 3\n";
    default : 
    cout<<"Using the default value of the number\n";
  }
  return 0;
}
