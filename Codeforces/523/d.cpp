#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

const int maxn = 100000;
const int mod = 1e9 + 7;
int lv[maxn+5];
int rv[maxn+5];
int n, x, y;
typedef pair<int, int> II;

int main() {
  scanf("%d %d %d", &n, &x, &y);

  int ans = 0;
  vector<II> iv;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &lv[i], &rv[i]);
    iv.push_back(make_pair(lv[i], 0));
    iv.push_back(make_pair(rv[i], 1));
    ans = (ans + ((rv[i] - lv[i]) * 1LL * y) % mod) % mod;
  }
  sort(iv.begin(), iv.end());
  stack<int> st;

  for(int i = 0; i < iv.size(); i++) {
    if(iv[i].second == 0) {
      if(st.empty() || (iv[i].first - st.top()) * 1LL * y > x) {
	ans = (ans + x) % mod;
	//printf("at %d add a new machine\n", iv[i].first);
      } else {
	ans = (ans + ((iv[i].first - st.top()) * 1LL * y) % mod) % mod;
	//printf("at %d used %d\n", iv[i].first, st.top());
	st.pop();
      }
    } else {
      st.push(iv[i].first);
    }
  }

  printf("%d\n", ans);
  
  return 0;
}
