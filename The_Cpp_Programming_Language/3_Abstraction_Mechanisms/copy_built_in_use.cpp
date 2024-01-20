// use of built-in copy function in c++
#include <iostream>
using namespace std;

int main() {

  vector<int> a{1, 2, 3, 4, 5};
  vector<int> b;
  copy(a.begin(), a.end(), back_inserter(b));

  cout << "Number of elements in b are : " << b.size() << "\n";
  for (int i = 0; i < b.size(); i++)
    cout << b[i] << " ";

  return 0;
}
