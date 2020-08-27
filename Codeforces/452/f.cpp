#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200000;
char str[maxn+5];
int n, m;
map<char, vector<int> > pos;
int bit[maxn+5];

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x) {
  while(x <= n) {
    bit[x] += 1;
    x += lowbit(x);
  }
}

int find_idx(int x) {
  int l = 1, r = n;
  while(l != r) {
    int mid = (l + r) >> 1;
    int s = sum(mid);
    if(mid - s >= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  scanf("%d%d\n", &n, &m);
  scanf("%s", str);
  for(int i = 0; i < n; i++) {
    if(pos.count(str[i])) {
      pos[str[i]].push_back(i+1);
    } else {
      pos[str[i]] = {i+1};
    }
  }
  memset(bit, 0, sizeof bit);
  while(m--) {
    int l, r;
    char c;
    scanf("%d %d %c\n", &l, &r, &c);
    int ll = find_idx(l);
    int rr = find_idx(r);
    vector<int>& indices = pos[c];
    vector<int> new_indices;
    for(int i = 0; i < indices.size(); i++) {
      if(indices[i] < ll || indices[i] > rr) {
	new_indices.push_back(indices[i]);
      } else {
	add(indices[i]);
      }
    }
    pos[c] = new_indices;
  }
  vector<pair<int, char> > ans;
  for(map<char, vector<int> >::iterator itr = pos.begin(); itr != pos.end(); itr++) {
    for(int i = 0; i < itr->second.size(); i++) {
      ans.push_back(make_pair(itr->second[i], itr->first));
    }
  }
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++) {
    printf("%c", ans[i].second);
  }
  printf("\n");
  return 0;
}
