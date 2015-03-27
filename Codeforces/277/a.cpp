#include <iostream>

using namespace std;

int main() {
  long long num;
  cin >> num;
  cout << (num % 2 == 1 ? -(num/2+1) : num/2) << endl;
  return 0;
}
