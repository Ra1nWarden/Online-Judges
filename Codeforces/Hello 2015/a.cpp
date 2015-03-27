#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  long long v[n];
  long long a;
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    v[i] = sum;
  }
  long long t;
  for(int i = 0; i < q; i++) {
    cin >> t;
    t %= sum;
    int result = lower_bound(v, v+n, t) - v;
    if(v[result] == t)
      result++;
    cout << result+1  << endl;
  }
  
  return 0;
}
