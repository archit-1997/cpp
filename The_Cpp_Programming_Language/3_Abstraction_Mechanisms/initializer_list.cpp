// user defined container (vector) with initializer list
#include <iostream>
using namespace std;

class Vector {
public:
  Vector(int s) : elem{new double[s]}, sz{s} {}

  int size() { return sz; }

  double &operator[](int i) { return elem[i]; }

  // initializer list
  Vector(std::initializer_list<double> lst)
      : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    copy(lst.begin(), lst.end(), elem);
  }

private:
  int sz;
  double *elem;
};

int main() {

  Vector v{5, 4, 3, 2, 1};

  // printing the elements of the vector
  for (int i = 0; i < v.size(); i++) {
    cout << "Value of element at index " << i << " is " << v[i] << "\n";
  }

  return 0;
}
