#include <cstdio>
#include <iostream>
#include <utility>
#define MAXN 500010

using namespace std;

int n, m;

typedef long long LL;
typedef pair<int, int> Interval;

LL prefix_sum[MAXN];

LL sum(int L, int R) {
  return prefix_sum[R] - prefix_sum[L-1];
}

LL sum(Interval p) {
  return sum(p.first, p.second);
}

Interval better(Interval a, Interval b) {
  if(sum(a) != sum(b))
    return sum(a) > sum(b) ? a : b;
  return a < b ? a : b;
}

int qL, qR;

struct SegTree {
  int max_prefix[2 * MAXN];
  int max_suffix[2 * MAXN];
  Interval max_sub[2 * MAXN];
  
  void build(int i, int L, int R) {
    if(L == R) {
      max_prefix[i] = max_suffix[i] = L;
      max_sub[i] = make_pair(L, R);
    } else {
      int mid = (L + R) / 2;
      int lc = i * 2;
      int rc = i * 2 + 1;
      build(lc, L, mid);
      build(rc, mid+1, R);

      
      LL lres = sum(L, max_prefix[lc]);
      LL rres = sum(L, max_prefix[rc]);
      if(lres == rres)
	max_prefix[i] = min(max_prefix[lc], max_prefix[rc]);
      else
	max_prefix[i] = lres > rres ? max_prefix[lc] : max_prefix[rc];

      lres = sum(max_suffix[lc], R);
      rres = sum(max_suffix[rc], R);
      if(lres == rres)
	max_suffix[i] = min(max_suffix[lc], max_suffix[rc]);
      else
	max_suffix[i] = lres > rres ? max_suffix[lc] : max_suffix[rc];

      max_sub[i] = better(max_sub[lc], max_sub[rc]);
      max_sub[i] = better(max_sub[i], make_pair(max_suffix[lc], max_prefix[rc]));
    }
  }

  Interval query_prefix(int i, int L, int R) {
    if(max_prefix[i] <= qR)
      return make_pair(L, max_prefix[i]);
    int mid = (L+R) / 2;
    int lc = i*2;
    int rc = i*2 + 1;
    if(qR <= mid)
      return query_prefix(lc, L, mid);
    Interval o = query_prefix(rc, mid+1, R);
    o.first = L;
    return better(o, make_pair(L, max_prefix[lc]));
  }

  Interval query_suffix(int i, int L, int R) {
    if(max_suffix[i] >= qL)
      return make_pair(max_suffix[i], R);
    int mid = (L + R) / 2;
    int lc = i * 2;
    int rc = i * 2+ 1;
    if(qL > mid)
      return query_suffix(rc, mid+1, R);
    Interval o = query_suffix(lc, L, mid);
    o.second = R;
    return better(o, make_pair(max_suffix[rc], R));
  }
  
  Interval query(int i, int L, int R) {
    if(qL <= L && R <= qR)
      return max_sub[i];
    int mid = (L+R) / 2;
    int lc = i * 2;
    int rc = i * 2+ 1;
    if(qR <= mid)
      return query(lc, L, mid);
    if(qL > mid)
      return query(rc, mid+1, R);
    Interval i1 = query_prefix(rc, mid+1, R);
    Interval i2 = query_suffix(lc, L, mid);
    Interval i3 = better(query(lc, L, mid), query(rc, mid+1, R));
    return better(make_pair(i2.first, i1.second), i3);
  }

};

SegTree tree;

int main() {
  int tc = 1;
  while(scanf("%d %d", &n, &m) != EOF) {
    prefix_sum[0] = 0;
    for(int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      prefix_sum[i+1] = prefix_sum[i] + x;
    }
    tree.build(1, 1, n);
    printf("Case %d:\n", tc++);
    for(int i = 0; i < m; i++) {
      scanf("%d %d", &qL, &qR);
      Interval ans = tree.query(1, 1, n);
      printf("%d %d\n", ans.first, ans.second);
    }
  }
  return 0;
}
