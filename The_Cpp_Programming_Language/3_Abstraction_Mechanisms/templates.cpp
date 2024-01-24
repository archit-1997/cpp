// A template is a (class or a function) that we parameterize with a set of
// (types or values). Templates : concept of generic programming Write code that
// works for all, eg vector<int> and vector<double> vector<> template should be
// independent of the type that we provide (except for few functionalities)
// Previously : we've created a class vector that only caters to vector of
// doubles. We can make that class generic to be a vector of any type by making
// it a template replace the type double with a parameter

// let's write a vector, and then we'll parameterize it
#include <iostream>
using namespace std;

template <typename T> // this make T as the parameter of the declaration it
class Vector {
public:
  Vector(int sz) : elem{new T[sz]}, sz{sz} {}
  ~Vector() { delete[] elem; }
  // Vector(initializer_list<T> ld)
  //     : elem{new T[ld.size()]}, sz{static_cast<int>(ld.size())} {
  //   copy(ld.begin(), ld.end(), elem);
  // }
  int size() { return sz; }
  T &operator[](int i) { return elem[i]; }
  // adding support for range based for loop

private:
  int sz;
  T *elem;
};

template <typename T> T *begin(Vector<T> &v) { return &v[0]; }
template <typename T> T *end(Vector<T> &v) { return (v.begin() + v.size()); }

int main() {
  Vector<double> v(5);
  for (int i = 0; i < v.size(); i++)
    v[i] = i * 5;
  // for (int i = 0; i < v.size(); i++)
  //   cout << "Element at index " << i << " is : " << v[i] << "\n";
  for (auto &x : v) {
    cout << x << "\n";
  }
}
