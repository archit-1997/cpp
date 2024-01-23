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
                      // prefixes
class Vector {
public:
  Vector(int sz) : elem{new T[sz]}, sz{sz} {}
  ~Vector() { delete[] elem; }
  Vector(initializer_list<T> ld)
      : elem{new T[ld.size()]}, sz{static_cast<int>(ld.size())} {
    copy(ld.begin(), ld.end(), elem);
  }
  int size() { return sz; }
  T &operator[](int i) { return elem[i]; }

private:
  int sz;
  T *elem;
};

int main() {
  Vector<double> v{1, 2, 3};
  Vector<int> v1;
  for (int i = 0; i < v.size(); i++)
    cout << "Element at index " << i << " is : " << v[i] << "\n";
}
