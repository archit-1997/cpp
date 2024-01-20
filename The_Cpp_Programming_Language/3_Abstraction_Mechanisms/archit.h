class Archit{
public:
  //constructor
  Archit(int s);

  //operator overloading
  double& operator[](int i);

  //method to get the size of the vector
  int size();

private:
  int sz;
  double* elem;
};
