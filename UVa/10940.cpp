#include <iostream>

using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    int ncopy = n;
    int length = 0;
    while(ncopy != 0) {
      ncopy = ncopy >> 1;
      length++;
    }
    int mask = 1 << (length - 1);
    int offset = mask ^ n;
    if(offset == 0)
      cout << n << endl;
    else
      cout << offset * 2 << endl;
  }
  return 0;
}
