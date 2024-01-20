#include "archit.h" 

Archit::Archit(int s):elem{new double[s]},sz{s}{
}

double& Archit::operator[](int i){
  return elem[i];
}

int Archit::size(){
  return sz;
}
