#include <iostream>

using namespace std;

int choose(int a, int b) {
  long long result = 1;
  int j = 1;
  for(int i=  a; i >= a-b+1; i--) {
    result *= i;
    result /= j;
    j++;
  }
  return result;
}

int main() {
  int n, k;
  while(cin >> n >> k && (n || k)) {
    cout << choose(n, min(k, n-k)) << endl;
  }
  return 0;
}
