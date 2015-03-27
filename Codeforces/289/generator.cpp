#include <iostream>

using namespace std;


int main() {
  for(int i=  0; i < 500000; i++) {
    cout << (char) ((i % 26) + 'A');
  }
  cout << endl;
  return 0;
}
