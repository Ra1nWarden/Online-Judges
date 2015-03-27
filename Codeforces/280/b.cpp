#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> v;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  double result = (double) max(v[0] - 0, l - v[v.size() - 1]);
  for(int i= 1; i < v.size(); i++) {
    result = max(result, ((double) v[i] - v[i-1]) / 2.0);
  }
  printf("%.9f\n", result);
  return 0;
}
