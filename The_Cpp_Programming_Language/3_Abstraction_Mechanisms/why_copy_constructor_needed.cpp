// running this program :
// 1. run without making any change : things would work fine
// 2. comment the destructor. the file would compile and run fine.
// but would generate errors during runtime i.e. while printing the output
// a.out(12856,0x1d7921000) malloc: *** error for object 0x6000032ad240: pointer
// being freed was not allocated
//  a.out(12856,0x1d7921000) malloc: *** set a breakpoint in malloc_error_break
//  to debug [1]    12856 abort      ./a.out

#include <iostream>
using namespace std;

class Vector {
public:
  Vector(int sz) : elem{new double[sz]}, sz{sz} {}
  Vector(std::initializer_list<double> list)
      : elem{new double[list.size()]}, sz{static_cast<int>(list.size())} {
    copy(list.begin(), list.end(), elem);
  }

  int size() { return sz; }

  double &operator[](int i) { return elem[i]; }

  ~Vector() { delete[] elem; }

private:
  int sz;
  double *elem;
};

int main() {
  Vector v1{1, 2, 3};
  Vector v2 = v1;

  cout << "printing the elements of v1\n";
  for (int i = 0; i < v1.size(); i++)
    cout << "v1: Element at index " << i << " is " << v1[i]
         << ". Memory address is : " << &v1[i] << "\n";

  cout << "printing the elements of v2\n";
  for (int i = 0; i < v2.size(); i++)
    cout << "v2: Element at index " << i << " is " << v2[i]
         << ". Memory address is : " << &v2[i] << "\n";

  // NOTE : Memory address for v2 will be same as that of v1 because
  // there memberwise copy is being done.

  // NOTE : when running the program, you would see an erorr that the memory
  // that we're trying to free is not allocated. Reason : v2 is copied from v1
  // using memberwise copy i.e. both v1 and v2 are pointing to the same object
  // in memory. When the control goes out of scope of v1, the destructor is
  // called for v1. Now when the destructor is called for v2 to free the same
  // memory, we get the error because the memory has already been freed.
  //
  //
  // If we try to remove the destructor and then run, it would run fine.
  //
  //
  // This is the reason why for complex concrete types, we should implement copy
  // constructor.
  return 0;
}
