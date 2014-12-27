#include <iostream>

using namespace std;

long long v[1000001];

long long solve(long long i) {
  return ((i-1) * (i-2) / 2 - (i-1) + i / 2) / 2;
}

int main() {
  v[3] = 0;
  for(long long i = 4; i <= 1000000; i++) {
    v[i] = v[i-1] + solve(i);
  }
  int n;
  while(cin >> n && n >= 3)
    cout << v[n] << endl;
  return 0;
}
