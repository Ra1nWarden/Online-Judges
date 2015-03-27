#include <iostream>
#define INF 1e8

using namespace std;

int main() {
  int n;
  cin >> n;
  int v[n];
  int diff[n-1];
  int curmax = -1;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
    if(i != 0) {
      diff[i-1] = v[i] - v[i-1];
      curmax = max(curmax, diff[i-1]);
    }
  }
  int remax = INF;
  for(int i = 0; i < n - 2; i++) {
    if(diff[i] + diff[i+1] <= curmax) {
      cout << curmax << endl;;
      return 0;
    }
    else {
      remax = min(remax, diff[i] + diff[i+1]);
    }
  }
  cout << remax << endl;
  return 0;
}
