#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int maxn = 10;
const int maxm = 10000;
int v[maxn+1];
int phi[maxm+1];
int m, n;

int power(int b, int p, int mod) {
  int cur = 1;
  for(int i = 0; i < p; i++) {
    if(b == 1)
      break;
    cur *= b;
    if(cur >= mod)
      break;
  }
  if(cur >= mod)
    cur = mod;
  else
    cur = 0;
  if(p == 0)
    return 1;
  int ans = power(b * b % mod, p >> 1, mod);
  if(p & 1)
    ans = ans * b % mod;
  return ans + cur;
}

int solve(int depth, int mod) {
  if(depth == n - 1) {
    if(v[depth] >= mod)
      return v[depth] % mod + mod;
    return v[depth];
  }
  int p = solve(depth + 1, phi[mod]);
  return power(v[depth], p, mod);
}

void init() {
  for(int i = 1; i <= maxm; i++)
    phi[i] = i;
  for(int i = 2; i <= maxm; i++) {
    if(phi[i] == i) {
      for(int j = i + i; j <= maxm; j += i) {
	phi[j] = phi[j] / phi[i] * (phi[i] - 1);
      }
      phi[i]--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  init();
  string line;
  int kase = 1;
  while(getline(cin, line)) {
    if(line[0] == '#')
      break;
    stringstream ss(line.c_str());
    ss >> m >> n;
    for(int i = 0; i < n; i++)
      ss >> v[i];
    cout << "Case #" << (kase++) << ": " << solve(0, m) % m << endl;
  }
  return 0;
}
