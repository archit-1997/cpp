#include <iostream>
#include <thread>

// std::thread my_thread(f);
// f is a function defined somewhere
// once we start a thread, we need to decide :
// 1. Whether we need to wait for it to finish : my_thread.join();
// 2. Leave it to run on it's own : my_thread.detach();

// What if we don't decide whether to join or detach?
// Our std::thread object (my_thread in this case) would be destroyed,
// then your program will be terminated
// std::thread() destructor calls std::thread terminate()
// So it's important to join or detach thread even in case of exceptions.

// It might that that the thread itself not has finished eg. when we call
// detach , the thread will continue to run even though the thread object is
// destroyed. In such cases, we need to make sure that the data accessed by
// thread is valid until it's finished
// Eg : Let's say the thread functions holds pointers or references
// to local variables and the thread continues execution even after the
// function exits
//

// this is an example of a case where the thread keeps running,
// my_thread is detached i.e. it will keep running.
// but when the control goes out of func(), the thread is still running in the
// background after the control goes out, the next call to std::cout would
// access an already destroyed variable so this would produce undesired output
struct func {
  int &i;
  func(int &i_) : i(i_) {}
  void operator()() {
    for (unsigned j = 0; j < 1000000; ++j) {
      std::cout << j << "\n";
    }
  }
};

void oops() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  my_thread.detach(); // replacing this with my_thread.join() would produce
                      // correct results
}

int main() {

  std::thread oops_thread(oops);
  oops_thread.join();

  return 0;
}
