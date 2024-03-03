#include <iostream>

class Vector {
private:
  int *ptr_;
  int size_;

public:
  // Constructor : For initialising the data memebers with some default values
  Vector() : ptr_(nullptr), size_(0) {
    std::cout << "Inside Default Constructor\n";
  }

  // Copy Constructor
  Vector(const Vector &rhs) {
    std::cout << "Inside Copy Constructor\n";
    this->ptr_ = new int[rhs.size_];
    this->size_ = rhs.size_;
    std::copy(rhs.ptr_, rhs.ptr_ + rhs.size_, this->ptr_);
  }

  // Move Constructor
  Vector(Vector &&rhs) {
    std::cout << "Inside Move Constructor\n";
    this->ptr_ = std::exchange(rhs.ptr_, nullptr);
    this->size_ = std::exchange(rhs.size_, 0);
  }

  // By-value assignment operator
  Vector &operator=(Vector rhs) {
    std::cout << "Inside by-value assignment operator\n";
    rhs.swap(*this);
    return *this;
  }

  // Destructor
  ~Vector() {
    std::cout << "Inside Destructor\n";
    delete[] this->ptr_;
  };

  // Custom swap function that leverages std::swap
  // this is just for simplicty so that we can write a.swap(b)
  void swap(Vector &rhs) {
    std::cout << "Inside the custom swap function\n";
    std::swap(this->ptr_, rhs.ptr_);
    std::swap(this->size_, rhs.size_);
  }

  // A two argument swap function that leverages the above swap function
  // This is to make our types efficiently std::swappable
  friend void swap(Vector &a, Vector &b) { a.swap(b); }
};

int main() {

  std::cout << "Vector\n";
  Vector v1;
  Vector v2;
  // this will call the copy constructor(from the by-value assignment operator)
  v2 = v2;
  // this will call the move constructor(from the by-value assignment operator)
  v2 = std::move(v1);

  return 0;
}
