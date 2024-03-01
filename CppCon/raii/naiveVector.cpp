#include <iostream>

class NaiveVector {
private:
  int *ptr_;
  size_t size_;

public:
  NaiveVector() : ptr_(nullptr), size_(0) {}

  void push_back(int newValue) {
    int *newptr_ = new int[size_ + 1];
    // std::copy(a,b,c)
    // a : pointer pointing to the beginning of the source container
    // b : pointer pointing to the end of the source container till where the
    // elements have to be copied
    // c : pointer pointing to the beginning of the
    // destination container, where the elements have to be copied
    std::copy(ptr_, ptr_ + size_, newptr_);
    delete ptr_;
    ptr_ = newptr_;
    ptr_[size_++] = newValue;
  }

  size_t size() { return size_; }

  int &operator[](int index) { return ptr_[index]; }

  // copy constructor
  NaiveVector(const NaiveVector &naiveVector) {
    std::cout << "Copy Contructor : Deep Copied !!\n";
    ptr_ = new int[naiveVector.size_];
    size_ = naiveVector.size_;
    std::copy(naiveVector.ptr_, naiveVector.ptr_ + naiveVector.size_, ptr_);
  }

  // copy assignment constructor
  NaiveVector &operator=(const NaiveVector &naiveVector) {
    std::cout << "Copy Assignment Contructor : Deep Copied !!\n";
    delete[] ptr_;
    ptr_ = new int[naiveVector.size_];
    size_ = naiveVector.size_;
    std::copy(naiveVector.ptr_, naiveVector.ptr_ + naiveVector.size_, ptr_);
    return *this;
  }

  // Adding destructor to avoid memory leak
  ~NaiveVector() { delete[] ptr_; }
};

void printVector(NaiveVector &v) {
  for (auto i = 0; i < v.size(); i++)
    std::cout << v[i] << "\n";
}

int main() {

  std::cout << "Naive Vector\n";

  NaiveVector v;
  v.push_back(1);
  std::cout << "& v[0] before calling copy constructor\n";
  std::cout << &v[0] << "\n";
  {
    v.push_back(2);
    // now once v2 goes out of scope, destructor for v2 will be called.
    // becauase this is shallow copy, both v and v2 are pointing to the same
    // memory address. after the scope, memory allocated for v2 has been
    // destroyed. Post that, we're again trying to acces that memory which will
    // give us segmentation fault
    std::cout << "Now going to do deep copy !!\n";
    NaiveVector v2 = v;
  }

  std::cout << "& v[0] after calling copy constructor\n";
  std::cout << &v[0] << "\n";

  std::cout << "Printing the elements of NaiveVector v\n";
  printVector(v);

  NaiveVector v3;
  v3 = v;

  std::cout << "& v[0] after calling copy assignment constructor\n";
  std::cout << &v[0] << "\n";

  return 0;
}
