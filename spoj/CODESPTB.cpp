#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1000000;
int bit[maxn+5];

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ans = 0;
  while(x > 0) {
    ans += bit[x];
    x -= lowbit(x);
  }
  return ans;
}

void add(int x, int d) {
  while(x <= maxn) {
    bit[x] += d;
    x += lowbit(x);
  }
}

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    memset(bit, 0, sizeof bit);
    int num;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      cin >> num;
      ans += (i - sum(num));
      add(num, 1);
    }
    cout << ans << endl;
  }
  return 0;
}
