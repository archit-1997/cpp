#include <iostream>
#include <thread>

class Callable {
public:
  void operator()() const { std::cout << "Callable class : doing something\n"; }
};

int main() {
  // default constructor being used in initialization
  Callable c, c1, c2;
  std::thread callable_thread1(c); // here the compiler automatically appends()
  // how? remember in hello_word() example? we just wrote the function name and
  // it was exectued

  // we can't write callable_thread(c());
  // Reason : std::thread callable_thread(c()) //this ist he syntax of a
  // function declaration so the compiler treats it's like that rather than a
  // thread object

  // Solution? : for some reason, these aren't working with my c compiler
  // Apple clang version 15.0.0 (clang-1500.1.0.2.5)
  // Target: arm64-apple-darwin23.2.0
  // Thread model: posix
  // InstalledDir: /Library/Developer/CommandLineTools/usr/bin

  // 1. callable_thread((c()));
  // 2. callable_thread{c()};
  callable_thread1.join();

  // std::thread callable_thread2(c()); //this would throw an error
  // //thread_with_callable.cpp:26:15: error: no matching constructor for
  // initialization of 'std::thread'
  // // std::thread callable_thread2(c());
  // callable_thread2.join();

  return 0;
}
