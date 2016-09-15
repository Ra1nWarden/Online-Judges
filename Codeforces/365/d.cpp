#include <cstdio>

using namespace std;

const int amxn = 1000000;
int v[maxn+5];
int prefix[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  int x = 0;
  prefix[0] = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    x ^= v[i];
    prefix[i] = x;
  }
  return 0;
}
