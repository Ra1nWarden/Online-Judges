#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> Range;
const int maxn = 3050;
int t1[2][maxn], t2[2][maxn], c[2][maxn], ra[2][maxn], sa[2][maxn], height[2][maxn], str[2][maxn];
int n;

void build_suffix_array(int m, int* t1, int* t2, int* c, int* ra, int* sa, int* height, int* str) {
  n++;
  int i, j, p, *x = t1, *y = t2;
  for(i = 0; i < m; i++) c[i] = 0;
  for(i = 0; i < n; i++) c[x[i] = str[i]]++;
  for(i = 1; i < m; i++) c[i] += c[i-1];
  for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
  for(j = 1; j <= n; j <<= 1) {
    p = 0;
    for(i = n-j; i < n; i++) y[p++] = i;
    for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[y[i]]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1; x[sa[0]] = 0;
    for(i = 1; i < n; i++)
      x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? p - 1 : p++;
    if(p >= n) break;
    m = p;
  }
  int k = 0;
  n--;
  for(i = 0; i <= n; i++) ra[sa[i]] = i;
  for(i = 0; i < n; i++) {
    if(k) k--;
    j = sa[ra[i] - 1];
    while(str[i+k] == str[j+k]) k++;
    height[ra[i]] = k;
  }
}

char s[maxn], t[maxn];
int sn, tn;

Range calc(int next_idx, int* ra, int* str) {
  int l = 0, r = sn;
  int len = 0;
  while(next_idx + len < tn && l <= r) {
    //printf("l=%d r=%d\n", l, r);
    if(l == r) {
      if(str[ra[l] + len] != t[next_idx + len]) {
	break;
      } else {
	len++;
      }
    } else {
      int check = t[next_idx + len];
      int ll = l, rr = r;
      while(ll != rr) {
	int m = (ll + rr) >> 1;
	if(ra[m] + len < sn && str[ra[m] + len] >= t[next_idx + len])
	  rr = m;
	else
	  ll = m + 1;
      }
      int new_l = ll;
      ll = l, rr = r;
      while(ll != rr) {
	int m = (ll + rr) >> 1;
	if(ra[m] + len < sn && str[ra[m] + len] > t[next_idx + len])
	  rr = m;
	else
	  ll = m + 1;
      }
      int new_r = ll;
      l = new_l, r = new_r;
      if(new_l == new_r) {
	if(str[ra[new_l] + len] != t[next_idx + len]) {
	  break;
	}
      } else if(str[ra[new_r] + len] > t[next_idx + len]) {
	r--;
      }
      len++;
    }
    //printf("end l=%d r=%d\n", l, r);
  }
  if(len) {
    return make_pair(ra[l], ra[l] + len - 1);
  } else {
    return make_pair(-1, -1);
  }
}

int main() {
  scanf("%s\n%s", s, t);
  sn = strlen(s);
  tn = strlen(t);
  n = sn;
  for(int i = 0; i < sn; i++) {
    str[0][i] = s[i];
  }
  str[0][sn] = 0;
  for(int i = 0; i < sn; i++) {
    str[1][i] = s[sn - 1 - i];
  }
  str[1][sn] = 0;
  int maxc = (int) 'z' + 1;
  // for(int i = 0; i <= sn; i++) {
  //   printf("%d ", str[0][i]);
  // }
  // printf("\n");
  // for(int i = 0; i <= sn; i++) {
  //   printf("%d ", str[1][i]);
  // }
  // printf("\n");
  // printf("maxc is %d\n", maxc);
  build_suffix_array(maxc, t1[0], t2[0], c[0], ra[0], sa[0], height[0], str[0]);
  build_suffix_array(maxc, t1[1], t2[1], c[1], ra[1], sa[1], height[1], str[1]);
  // for(int i = 0; i <= sn; i++) {
  //   printf("forward %d rank = %d\n", i, sa[0][i]);
  //   printf("backward %d rank = %d\n", i, ra[1][i]);
  // }
  vector<Range> ans;
  int next_idx = 0;
  while(next_idx < tn) {
    Range forward = calc(next_idx, sa[0], str[0]);
    //printf("next_idx is %d forward is %d to %d\n", next_idx, forward.first, forward.second);
    if(forward.first == -1) {
      ans.clear();
      break;
    }
    Range backward = calc(next_idx, sa[1], str[1]);
    backward.first = sn - 1 - backward.first;
    backward.second = sn - 1 - backward.second;
    //printf("next_idx is %d backward is %d to %d\n", next_idx, backward.first, backward.second);
    if(forward.second - forward.first > backward.first - backward.second) {
      ans.push_back(forward);
      next_idx += forward.second - forward.first + 1;
    } else {
      ans.push_back(backward);
      next_idx += backward.first - backward.second + 1;
    }
  }
  if(ans.empty()) {
    printf("-1\n");
  } else {
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
      printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
  }
  return 0;
}
