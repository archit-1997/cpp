#include <iostream>

class NaiveVector {
private:
  int *ptr_;
  size_t size_;

public:
  NaiveVector() : ptr_(nullptr), size_(0) {

    std::cout << "Default Constructor called\n";
  }

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
  NaiveVector(const NaiveVector &rhs) {
    std::cout << "Copy Contructor : Deep Copied !!\n";
    this->ptr_ = new int[rhs.size_];
    this->size_ = rhs.size_;
    std::copy(rhs.ptr_, rhs.ptr_ + rhs.size_, this->ptr_);
  }

  // Method to swap two pointers
  void swap(NaiveVector &a, NaiveVector &b) {
    std::cout << "Swap method called \n";
    // copying the value of ptr_
    int *tmp_ptr = a.ptr_;
    a.ptr_ = b.ptr_;
    b.ptr_ = tmp_ptr;
    // copying the value of size_
    int tmp_size = a.size_;
    a.size_ = b.size_;
    b.size_ = tmp_size;
  }

  // Self copyable copy assingment constructor
  NaiveVector &operator=(const NaiveVector &rhs) {
    // to avoid memory leak
    // let's say we created NaiveVector v3; and did v3.push_back a couple of
    // times Now if we do v3=v, so we'll have to delete the memory to which v3
    // was previously pointing to
    std::cout << "Copy Assignment Contructor : Deep Copied !!\n";
    std::cout << "Going to call copy constructor inside conopy assignment "
                 "constructor\n";
    // This will not generate memory leak because when copy goes out of scope,
    // the destructor will be called.
    NaiveVector copy = rhs;
    // we need to swap the contents of copy and *this
    swap(copy, *this);
    return *this;
  }

  // Adding destructor to avoid memory leak
  ~NaiveVector() {
    std::cout << "Destructor is called\n";
    delete[] ptr_;
  }
};

void printVector(NaiveVector &v) {
  for (auto i = 0; i < v.size(); i++)
    std::cout << v[i] << "\n";
}

int main() {

  std::cout << "Naive Vector\n";

  NaiveVector v;
  v.push_back(1);
  std::cout << "v[0] after v.push_back(1) " << &v[0] << "\n";
  {
    v.push_back(2);
    // now once v2 goes out of scope, destructor for v2 will be called.
    std::cout << "v[0] after v.push_back(2) " << &v[0] << "\n";
    // becauase this is shallow copy, both v and v2 are pointing to the same
    // memory address. after the scope, memory allocated for v2 has been
    // destroyed. Post that, we're again trying to acces that memory which will
    // give us segmentation fault
    std::cout << "Now going to call copy constructor for deep copy!!\n";
    // NOTE: Here only copy constructor will be called. Default constructor
    // won't be called.
    NaiveVector v2 = v;
  }

  std::cout << "v[0] after calling copy constructor " << &v[0] << "\n";

  std::cout << "Printing the elements of NaiveVector v\n";
  printVector(v);

  std ::cout << " Will now call default constructor again!!\n";
  NaiveVector v3;
  v3 = v;

  std::cout << "v[0] after calling copy assignment constructor " << &v[0]
            << "\n";

  std::cout << "Printing the elements of NaiveVector v3\n";
  printVector(v3);

  std::cout << "Teseting if copy assignment constructor is self copyable\n";
  v3 = v3;

  return 0;
}
