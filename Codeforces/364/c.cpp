#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100000;
const int maxa = 60;
vector<int> s[maxa+5];
char str[maxn+5];

int decode(char c) {
  if(c >= 'a' && c <= 'z') {
    return c - 'a';
  } else {
    return 26 + (c - 'A');
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  scanf("%s", str);
  for(int i = 0; i < n; i++) {
    s[decode(str[i])].push_back(i);
  }
  int ans = n;
  for(int i = 0; i < n; i++) {
    // go left
    bool ok = true;
    int cur = 1;
    for(int j = 0; j < 52; j++) {
      if(decode(str[i]) == j)
	continue;
      if(s[j].empty())
	continue;
      vector<int>::iterator itr = lower_bound(s[j].begin(), s[j].end(), i);
      if(itr == s[j].begin()) {
	ok = false;
	break;
      } else {
	itr--;
	cur = max(cur, i - (*itr) + 1);
      }
    }
    if(ok) {
      ans = min(ans, cur);
    }
    // go right
    ok = true;
    cur = 1;
    for(int j = 0; j < 52; j++) {
      if(decode(str[i]) == j)
	continue;
      if(s[j].empty())
	continue;
      vector<int>::iterator itr = upper_bound(s[j].begin(), s[j].end(), i);
      if(itr == s[j].end()) {
	ok = false;
	break;
      } else {
	cur = max(cur, (*itr) - i + 1);
      }
    }
    if(ok) {
      ans = min(ans, cur);
    }
  }
  printf("%d\n", ans);
  return 0;
}
