#include <iostream>

using namespace std;

int main() {
  cout << 1 << endl;
  cout << 50000 << endl;
  for(int i = 0; i < 50000; i++) {
    cout << i % 50 + 1 << " ";
  }
  for(int i = 0; i < 40000 - 1; i++) {
    if(i % 3 == 0)
      cout << "Query " << 1 << " " << i+1 << endl;
    if(i % 3 == 1)
      cout << "Add " << i+1 << " " << i+2 << endl;
    if(i % 3 == 2)
      cout << "Sub " << i+2 << " " << i - 1 << endl;
  }
  cout << "End" << endl;
  return 0;
}
