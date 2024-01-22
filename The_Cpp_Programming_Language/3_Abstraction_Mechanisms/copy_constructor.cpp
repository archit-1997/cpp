// example of vector with copy container
#include <iostream>
using namespace std;

class Vector {
public:
  // constructor
  Vector(int s) : elem{new double[s]}, sz{s} {}

  Vector(initializer_list<double> ld)
      : elem{new double[ld.size()]}, sz{static_cast<int>(ld.size())} {
    copy(ld.begin(), ld.end(), elem);
  }

  // destructor
  ~Vector() { delete[] elem; }

  // copy constructor
  Vector(const Vector &a);

  // copy assignment
  Vector &operator=(const Vector &a);

  //[]operator overloading
  double &operator[](int i) { return elem[i]; }

  //+ operator overloading
  int size() { return sz; }

private:
  int sz;
  double *elem;
};

// NOTE : We can't declare this function inside the Vector class
// Reason : We'll get the below error on compilation :
// copy_constructor.cpp:27:10: error: overloaded 'operator+' must be a unary or
// binary operator (has 3 parameters)
//  Vector operator+(Vector &a, Vector &b) {
// Member functions by default have an implicit parameter this. Now + is a
// binary operator. But arguments passed to this function are 3 : this, a and b
// to solve this problem, we'll have to define operator+ outside the Vector
// class i.e. making this a non-member function
// now why can't an operator expect 3 parameters?
// there is only one such operator ? but it's not possible to overload ?
// parameter in c++ by definition
Vector operator+(Vector &a, Vector &b) {
  if (a.size() != b.size())
    throw out_of_range("Array sizes are not equal!!");
  Vector res(a.size());
  for (int i = 0; i < a.size(); i++)
    res[i] = a[i] + b[i];
  return res;
}

// NOTE : A copy constructor and a copy assignment for a class X are typically
// declared to take an argument
//  of type const X&.

// copy constructor
// here we've allocated memory for elem and then copied the elements from a to
// Questions : how is the copy constructor able to work without specifying a.sz?
Vector::Vector(const Vector &a) : elem{new double[a.sz]}, sz{a.sz} {
  for (int i = 0; i < a.sz; i++)
    elem[i] = a.elem[i];
}

// copy assignment
Vector &Vector::operator=(const Vector &a) {
  double *p = new double[a.sz];
  for (int i = 0; i < a.sz; i++)
    p[i] = a.elem[i];
  delete[] elem; // delete old elements
  // what is the meaning of delete[] older elements?
  elem = p;
  sz = a.sz;
  return *this;
  //   The name this is predefined in a member function and points to the object
  //   for which the member
  // function is called.
}
//
int main() {

  Vector v1{1, 2, 3};
  Vector v2 = v1;
  Vector v3 = v2 + v1;

  cout << "Printing the elments of vector v1\n";
  for (int i = 0; i < v1.size(); i++)
    cout << "v1 : Element at index " << i << " is : " << v1[i]
         << ". Memory Address : " << &v1[i] << "\n";

  cout << "Printing the elments of vector v2\n";
  for (int i = 0; i < v2.size(); i++)
    cout << "v2 : Element at index " << i << " is : " << v2[i]
         << ". Memory Address : " << &v2[i] << "\n";

  cout << "Printing the elments of vector v3\n";
  for (int i = 0; i < v3.size(); i++)
    cout << "v3 : Element at index " << i << " is : " << v3[i]
         << ". Memory Address : " << &v3[i] << "\n";

  cout << "Hello World!!";
  return 0;
}
