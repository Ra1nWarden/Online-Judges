#include <iostream>
#include <cstring>
#define MAXN 100002
#define MOD 1000000000L

using namespace std;

int n, q, f1, f2, l, r, nexti, a, b;
int v[MAXN];
int f[MAXN];

int func(int x) {
  if(x < nexti)
    return f[x];
  for(int i = nexti; i <= x; i++) {
    f[i] = a * f[i-2] + b * f[i-1];
  }
  nexti = x+1;
  return f[x];
}

int main() {
  memset(f, -1, sizeof f);
  cin >> n >> q >> f[1] >> f[2] >> a >> b;
  nexti = 3;
  int x;
  for(int i = 1; i <= n; i++) {
    cin >> x;
    v[i] = x;
  }
  for(int j = 0; j < q; j++) {
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
      int diff = i - l + 1;
      int add = func(diff);
      v[i] = (int) (((long long) v[i] + (long long) add) % MOD);
    }
#ifdef _DEBUG
    cout << "after an opration between " << l << " and " << r << ": " << endl;
    for(int i = 1; i < n+1; i++)
      cout << "v[" << i << "] = " << v[i] << endl;
#endif
  }
  for(int i = 1; i <= n; i++) {
    if(i != 1)
      cout << " ";
    cout << v[i];
  }
  cout << endl;

#ifdef _DEBUG
  for(int i = 1; i < n+2; i++)
    cout << "f(" << i << ") = " << f[i] << endl;
#endif

  return 0;
}
