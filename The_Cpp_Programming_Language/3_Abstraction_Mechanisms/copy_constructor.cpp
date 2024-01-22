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

  int size() { return sz; }

private:
  int sz;
  double *elem;
};

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
  //   The name this is predefined in a member function and points to the
  // function is called.
}
//
int main() {

  Vector v1{1, 2, 3};
  Vector v2 = v1;

  cout << "Printing the elments of vector v1\n";
  for (int i = 0; i < v1.size(); i++)
    cout << "v1 : Element at index " << i << " is : " << v1[i]
         << ". Memory Address : " << &v1[i] << "\n";

  cout << "Printing the elments of vector v2\n";
  for (int i = 0; i < v2.size(); i++)
    cout << "v2 : Element at index " << i << " is : " << v2[i]
         << ". Memory Address : " << &v2[i] << "\n";

  cout << "Hello World!!";
  return 0;
}
