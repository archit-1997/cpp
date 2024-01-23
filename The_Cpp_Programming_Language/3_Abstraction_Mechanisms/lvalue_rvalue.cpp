#include <iostream>
using namespace std;

int &getValue() {
  static int value = 10;
  return value;
}

void setValue(int num) { num = 10; }

void printName(const string &name) {
  cout << "Name of the string is : " << name << "\n";
}

void printRName(const string &&name) { cout << "Rvalue is : " << name << "\n"; }

int main() {

  // left side || right side
  // lvlaue : something that is on the left hand side of =
  // rvalue : something that is on the right hand side of =
  // i is a variable which has some location in memory
  // 10 : something that has a constant value, 10 itself has no location or
  // storage until it is assigned to an lvalue 10 = i; this is something that is
  // not possible, we cannot assign an lvalue to an rvalue int a=i it's
  // possible, we can assign an lvalue to another lvalue an rvalue doesn't
  // necessarily have to be a literal, it can also be the result of a function
  // int i = getvalue(); getValue() is returning an rvalue.
  // Ques : how come it returns an rvalue given that 10 is constant?
  // this is because 10 is just being returned. It isn't stored at a memory
  // location.
  int i = getValue();
  // getValue() = 5; // this is also not possible because the value returned
  // from getValue() is not modifiable

  // how to make getValue() allow something to be assigned to it?
  // we need getValue() to return an lvalue_reference instead of lvalue so that
  // something can be assinged to it
  getValue() = 5;

  // we can also call a function with an lvalue and an rvalue
  // calling setValue with an lvalue(something that is modifiable)
  setValue(i);
  // calling setvalue with an rvalue(something that is not modifiable)
  setValue(10);

  // Rule : You cannot take an value reference from an rvalue
  // You can only have an lvalue reference of an lvalue (never possible of an
  // rvalue) eg : void setValue(int& num) this will not accept the rvalue i.e.
  // setValue(10)

  // you can take an rvalue into an lvalue ref, but that ref_lvalue should be
  // const so a const lvalue_reference can take an lvalue as well as an rvalue
  // setvalue(const int& val)

  // another example
  string fname = "Archit";
  string sname = "Singh";
  string name = fname + sname;
  printName(name);
  printName(fname + sname);
  const int &a = 10;

  // we;ve seen examples where we can pass value(which are constant) to
  // lvalues_references we've also seen that we are passing rvalue to const
  // lvalue_reference

  // is there a way where we can only pass temporary objects ?
  // Yes. And that is called rvalue reference.
  printRName(fname + sname);
  // printRName(name);  //this will throw an error because rvalue refernce
  // excepts an rvalue and we're passing an lvalue

  // Usecase
  // lvalues are permanent
  // rvalue are temporarily : if we that we don't need something after a while
  // we can pass them as rvalue reference and then after copying, release the
  // resources rvalue reference is helpful in move semantics
  return 0;
}
