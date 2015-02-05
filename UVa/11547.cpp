#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int number;
    cin >> number;
    cout << abs(((number * 567 / 9 + 7492) * 235 / 47 - 498) % 100 / 10) << endl;
  }
  return 0;
}
