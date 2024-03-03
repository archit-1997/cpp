#include <iostream>

class Vector {
private:
  std::unique_ptr<int[]> ptr_;
  int size_;

public:
  // copy contructor
  Vector(const Vector &rhs) {
    ptr_ = std::make_unique<int[]>(rhs.size_);
    size_ = rhs.size_;
    // how to resolve the syntax error here?
    std::copy(rhs.ptr_, rhs.ptr_ + size_, ptr_);
  }

  // move contructor
  // We can use the default implementation of the move constructor because
  // unique pointers move constructor will now take care of the move semantics
  Vector(Vector &&rhs) = default;

  // Destructor
  // We don't need to explicitly delete ptr_ because it's a unique pointer
  // and it can manage it's lifecycle on its own
  ~Vector() = default;

  // by-value copy assignment operator
  Vector &operator=(Vector rhs) {
    rhs.swap(*this);
    return *this;
  }

  void swap(Vector &a) {
    std::swap(this->ptr_, a.ptr_);
    std::swap(this->size_, a.size_);
  }

  friend void swap(Vector &a, Vector &b) { a.swap(b); }
};

int main() {

  std::cout << "Unique Vector\n";

  return 0;
}
