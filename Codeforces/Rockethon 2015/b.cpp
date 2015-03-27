#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long long m;

void solve(int* v, int depth) {
  if(n == depth) {
    v[0] = depth;
    return;
  }
  long long highest = (1LL << (n - depth - 1));
  //cout << "highest is " << highest << " after shifting " << n - depth - 1 << endl;
  if((m & highest) != 0) {
    // bit is set
    //cout << m << " and " << highest << endl;
    //cout << "bit is set at " << depth << endl;
    v[n - depth] = depth;
    //printf("if\n");
    solve(v, depth+1);
  } else {
    // bit is not set
    v[0] = depth;
    solve(v+1, depth+1);
  }
}

int main() {
  cin >> n >> m;
  m--;
  int v[n];
  solve(v, 1);
  for(int i = 0; i < n; i++) {
    if(i != 0)
      cout << " ";
    cout << v[i];
  }
  cout << endl;
  return 0;
}
