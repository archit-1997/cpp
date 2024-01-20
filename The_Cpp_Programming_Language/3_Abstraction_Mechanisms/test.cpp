#include <iostream>
#include "archit.h"
using namespace std;

int main(){
  
  cout<<"Enter the size of the vector\n";
  int s;cin>>s;

  Archit v(s);
  for(int i=0;i<s;i++){
    cout<<"Enter element " <<i+1<<"\n";
    cin>>v[i];
  }

  cout<<"Printing the elements of the vector\n";
  for(int i=0;i<s;i++){
    cout<<"Element " << i+1 << " is : " << v[i] <<"\n";
  }
  return 0;
}
