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

  // operator overloading
  char &operator[](int index) { return m_buffer[index]; }

  friend std::ostream &operator<<(std::ostream &stream, const String &string);

  ~String() { delete[] m_buffer; }
};

std::ostream &operator<<(std::ostream &stream, const String &string) {
  stream << string.m_buffer;
  return stream;
}

int main() {

  String name1 = "Archit";
  name1[0] = 'C';
  String name2 = name1;

  std::cout << name1 << "\n";
  std::cout << name2 << "\n";

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
