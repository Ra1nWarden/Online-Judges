#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1000000;
bool v[maxn+5];
vector<int> ans;

void init() {
  memset(v, true, sizeof v);
  for(int i = 2; i * i * i <= maxn; i++) {
    int c = i * i * i;
    for(int j = c; j <= maxn; j += c) {
      v[j] = false;
    }
  }
  for(int i = 1; i <= maxn; i++) {
    if(v[i])
      ans.push_back(i);
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int num;
    scanf("%d", &num);
    vector<int>::iterator itr = lower_bound(ans.begin(), ans.end(), num);
    if(itr == ans.end() || *itr != num)
      printf("Case %d: Not Cube Free\n", kase);
    else
      printf("Case %d: %d\n", kase, (itr - ans.begin()) + 1);
    
  }
  return 0;
}
