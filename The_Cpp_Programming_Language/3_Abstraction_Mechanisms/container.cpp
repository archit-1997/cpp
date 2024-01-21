// Abstract Class : Container
// given that this is an abstract class, the interfaces should be defined in
// public scope a class with pure virtual function is called an abstract class

// concrete class Vector
#include <iostream>
#include <list>
using namespace std;

class Vector {
public:
  Vector(int sz) : elem{new double[sz]}, sz{sz} {}
  // implementing the initializer list
  Vector(std::initializer_list<double> list)
      : elem{new double[list.size()]}, sz{static_cast<int>(list.size())} {
    copy(list.begin(), list.end(), elem);
  }
  int size() { return sz; }
  double &operator[](int i) { return elem[i]; }
  ~Vector() { delete[] elem; }

private:
  int sz;
  double *elem;
};

// Abstract class Container : has all the interfaces
// a class with pure virtual function is called an abstract class
class Container {
public:
  virtual double &
  operator[](int) = 0; // because this is interface, we just have the type in
                       // the parameter list, not the variable name
  virtual int
  size() = 0; // =0 means that both operator[] and size() are pure virtual
              // functions, meaning the implementor should define it
  virtual ~Container(){}; // destructor
};

// class Vector_container that implements Container(actually implements the
// interfaces in the Container class) class Vector_container is using the
// concerete class Vector for implementing the interfaces
class Vector_container
    : public Container { // public Container can be read as : `is derived from`
                         // or `is Subtype of `
  // class Vector_container is said to be derived from class Container
  // Container : base class(super class) of Vector_container (derived class or
  // subclass) This programming paradigm is called inheritence
  Vector v; // object of type concerete class Vector

public:
  Vector_container(int sz) : v(sz) {}
  Vector_container(std::initializer_list<double> list) : v(list){}
  double &operator[](int i) { return v[i]; }

  int size() { return v.size(); }
  ~Vector_container(){}; // this will implicitly call the destructor of the
                         // concrete class Vector
};

//adding another implementation of Container : List_Container
class List_container : public Container {
public : 
  //explicitly specified the default constructor
  List_container(){}
  //parameterized constructor
  List_container(std::initializer_list<double> ld) : list_double{ld}{}
  //destructor
  ~List_container(){}
  double& operator[](int i){
    //implemented out of range for accessor
    for(auto& elem : list_double){
      //we need to return the ith element. so when i==0, we have to return the value of the list
      if(i==0)
        return elem;
      --i;
    }
    //if we've reached here, then that means that we should throw out of bounds
    throw out_of_range("List Container !!");
  }
  int size(){
    return list_double.size();
  }
  
private : 
  list<double> list_double;
};

//a method that only knows about the interface Container
//this doesn't need to know how the interface has been implemented
//this method will work for any implementation of the interface container
void printContainer(Container& c){
  cout<<"Printing from the printContainer method\n";
  for(int i=0;i<c.size();i++)
    cout<<c[i] <<"\n";
  cout<<"Done printing from the printContainer method\n";
}



int main() {

  cout << "Enter the size of the container\n";
  int sz;
  cin >> sz;

  Vector_container v(sz);

  for (int i = 0; i < v.size(); i++) {
    cout << "Enter element number : " << (i + 1) << "\n";
    cin >> v[i];
  }

  // printing the elments of the vector
  for (int i = 0; i < v.size(); i++) {
    cout << "Element at index " << i << " is : " << v[i] << "\n";
  }
  
  //now using the initializer list
  Vector_container vl{7,6,5};

  cout<<"Printing the elements of the initializer list\n" ;
  for(int i=0;i<vl.size();i++)
    cout<<"Element at index " << i << " in the initializer list is : " << vl[i]<<"\n";

  printContainer(v);
  printContainer(vl);


  //using the ListContainer
  List_container ls{1,2,3};

  cout<<"Printing the elments of the List_container \n";
  for(int i=0;i<ls.size();i++){
    cout<<"Element at index " << i << " in the list is " << ls[i]<<"\n";
  }
  cout<<"Done printing elments of the List_container \n";

  return 0;
}
