#include <iostream>
#include <string>
#include <thread>

class MyThread : public std::thread {
private:
  int thread_id;
  std::string thread_name;
  std::thread my_thread;

public:
  MyThread() : thread_id(777), thread_name("Archit's MyThread") {}

  void print_with_thread() {
    std::cout << "I'm the print_with_thread method of MyThread class.\nI'll "
                 "call the print method of the same class, but using thread\n";

    // NOTE : Added &MyThread::hello because the compiler needs to know where is
    // the print_hello method.
    // 1. either we make it static
    // 2. or we pass a reference to it saying that this is a member function of
    // the class MyThread For reason 2, we've added & symbol.

    // Why are we passing this to the thread method?
    // because the print_hello() expects an instance of the class
    this->my_thread = std::move(std::thread(&MyThread::print_hello, this));
    this->my_thread.join();
  }

  void print_hello() {
    std::cout << "Hello World from thread\n";
    std::cout << "The thread id is : " << this->thread_id << "\n";
    std::cout << "The thread name is : " << this->thread_name << "\n";
  }
};

int main() {

  std::cout << "This is a class with std::thread as it's data member\n";
  MyThread mythread;
  mythread.print_with_thread();

  return 0;
}
