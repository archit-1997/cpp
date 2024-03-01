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

  friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

std::ostream &operator<<(std::ostream &stream, const String &string) {
  stream << string.m_buffer;
  return stream;
}

int main() {

  String name = "Archit";
  std::cout << name;
}
