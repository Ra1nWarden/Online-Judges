#include <iostream>

using namespace std;

long long CatalanR(long long n) {
  if(n == 0) {
    return 1;
  }
  return CatalanR(n - 1) * (4 * n - 2) / (n + 1);
}

int main() {
  int v[11];
  v[0] = 1;
  for(int i = 1; i < 11; i++)
    v[i] = v[i-1] * (4 * i - 2) / (i + 1);
  int n;
  bool init = true;
  while(cin >> n) {
    if(!init)
      cout << endl;
    cout << v[n] << endl;
    init = false;
  }
  return 0;
}
