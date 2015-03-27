#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;
  int prev = 0;
  for(int i = 1; i > 0; i++) {
    prev += i;
    x -= prev;
    if(x < 0) {
      cout << i - 1 << endl;
      break;
    }
  }
  return 0;
}
