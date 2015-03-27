#include <iostream>

using namespace std;

int main() {
  int n, m;
  while(cin >> n >> m) {
    cout << (m % n == 0 ? n - 1 : m % n - 1) << endl;
  }
  return 0;
}
