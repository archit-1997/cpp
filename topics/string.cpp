#include <iostream>

class String {
private:
  char *m_buffer;
  unsigned int m_size;

public:
  String(const char *string) {
    m_size = strlen(string);
    m_buffer = new char[m_size + 1];
    memcpy(m_buffer, string, m_size);
    m_buffer[m_size] = 0;
  }

  // NOTE : There is a default copy constructor provided by C++.
  // We can use this as well but this is also used to copy the data members
  // This also won't create a new object
  // String(const String &other) : m_buffer(other.m_buffer),
  // m_size(other.m_size) {
  //   memcpy(this, &other, size_of(string));
  // }

  // Seting the default copy constructor to delete to avoid shallow copy
  // String(const String &string) = delete;

  // overriding the default copy constructor to perform deep copy
  String(const String &other) : m_size(other.m_size) {
    // Added this print statement to demonstrate that when we're calling
    // printString function, then also we're doing deep copying which is getting
    // wasted.
    std::cout << "Deep Copied String\n";
    m_buffer = new char[m_size + 1];
    memcpy(m_buffer, other.m_buffer, m_size + 1);
  }

  // operator overloading []
  char &operator[](int index) { return m_buffer[index]; }

  // operator overloading <<
  friend std::ostream &operator<<(std::ostream &stream, const String &string);

  ~String() { delete[] m_buffer; }
};

// operator overloading <<
std::ostream &operator<<(std::ostream &stream, const String &string) {
  stream << string.m_buffer;
  return stream;
}

void printString(String string) { std::cout << string << "\n"; }

int main() {

  String name1 = "Archit";
  String name2 = name1;
  name1[0] = 'C';

  printString(name1);
  printString(name2);

  // Shallow Copy : The default copy done by c++
  // After excuting the above line, the compiler will generate a segmentation
  // fault
  // Why? This is because the memory hasn't been copied. So after the first cout
  // for name1 goes out of scope, the destructor is called and it deletes the
  // memory. Now after the second name2 goes out of scope, the destructor is
  // called. Because the same memory was allocated for name1 and name2, the
  // destructor will try to delete memory allocated to name2  but it has already
  // been deleted. This means it's trying to access/delete memory that doesn't
  // even exit. This is the reason we get segmentation fault.
}
