#include <iostream>
using namespace std;

class Vector {
public:
  Vector(int s) : elem{new double[s]}, sz{s} {}

  ~Vector() { delete[] elem; }

  Vector(std::initializer_list<double> list)
      : elem{new double[list.size()]}, sz{static_cast<int>(list.size())} {
    copy(list.begin(), list.end(), elem);
  }

  int size() { return sz; }

  double &operator[](int i) {
    // here we have to throw out_of_range
    if (i >= sz)
      throw out_of_range("Index out of bounds, you're trying to access invalid "
                         "memory address of Vector");
    return elem[i];
  }

private:
  int sz;
  double *elem;
};

int main() {

  Vector v{1, 2, 3};

  cout << "The size of vector v is : " << v.size() << "\n";

  for (int i = 0; i < v.size(); i++) {
    cout << "Element at index " << i << "is : " << v[i] << "\n";
  }

  cout << "let's access v[3]\n";
  cout << "v[3] is : " << v[3] << "\n";
  return 0;
}
