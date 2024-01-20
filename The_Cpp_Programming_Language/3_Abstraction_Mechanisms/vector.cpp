#include <iostream>
using namespace std;

class Vector{

public:
  Vector(int sz) :elem{new double[sz]},sz{sz}{
    for(int i=0;i<sz;i++){
      elem[i] =0;
    }
  }

  int size(){
    return sz;
  }

  double& operator[](int i){
    return elem[i];
  }

  ~Vector(){
    std::cout<<"Calling the destructor to deallocate memory\n";
    delete[] elem;
    std::cout<<"Destructor has successfully deallocated the memory\n";
  }

private : 
  int sz;
  double* elem;

};

void createAndPrintVector(){
  cout<<"Enter the size of the vector\n";
  int sz;cin>>sz;
  Vector v(sz);

  for(int i=0;i<v.size();i++){
    cout<<&v[i] <<"\n";
  }
}

int main(){
  createAndPrintVector();
  return 0;
}
