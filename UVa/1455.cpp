#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

const int maxn = 100000;
typedef pair<int, int> Point;
Point points[maxn+5];
int n;
const int maxl = 30;
char buffer[maxl];
int fa[maxn+5];
int cnt[maxn+5];

int find_set(int num) {
  return fa[num] == num ? num : fa[num] = find_set(fa[num]);
}

void union_set(int a, int b) {
  if(find_set(a) != find_set(b)) {
    cnt[find_set(b)] += cnt[find_set(a)];
    fa[find_set(a)] = find_set(b);
  }
}

struct Node {
  int l, r;
  set<int> v;
  Node() {};
};

struct SegmentTree {
  Node segTree[4000005]; // 4 is enough
  SegmentTree();
  void build(int i, int l, int r);
  void query(int i, int v, set<int>& ans);
  void add_range(int i, int l, int r, int val);
};

SegmentTree tree;

void init() {
  for(int i = 0; i < n; i++) {
    fa[i] = i;
    cnt[i] = 1;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    int maxy = 1;
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &points[i].first, &points[i].second);
      maxy = max(maxy, points[i].second);
    }
    init();
    tree.build(1, 1, maxy+1);
    int queries;
    scanf("%d\n", &queries);
    for(int i = 0; i < queries; i++) {
      fgets(buffer, sizeof buffer, stdin);
      //printf("command is %s\n", buffer);
      if(buffer[0] == 'r') {
	int a, b;
	sscanf(buffer, "road %d %d\n", &a, &b);
	union_set(a, b);
	//printf("union set %d %d\n", a, b);
	int l = min(points[a].second, points[b].second);
	int r = max(points[a].second, points[b].second);
	//printf("add range %d %d\n", l+1, r);
	if(l + 1 <= r)
	  tree.add_range(1, l + 1, r, find_set(a));
      } else if(buffer[0] == 'l') {
	int a;
	sscanf(buffer, "line %d.5\n", &a);
	set<int> s;
	tree.query(1, a + 1, s);
	set<int> exists;
	int ans1 = 0, ans2 = 0;
	//printf("query %d: \n", a + 1);
	for(set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
	  int b = find_set(*itr);
	  //printf("found parent %d\n", b);
	  if(!exists.count(b)) {
	    ans1++;
	    ans2 += cnt[b];
	    exists.insert(b);
	  }
	}
	printf("%d %d\n", ans1, ans2);
      }
    }
  }
  return 0;
}

SegmentTree::SegmentTree() {};

void SegmentTree::build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].v.clear();
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r)+1, r);
}

void SegmentTree::query(int i, int v, set<int>& ans) {
  for(set<int>::iterator itr = segTree[i].v.begin(); itr != segTree[i].v.end(); itr++) {
    ans.insert(*itr);
  }
  if(segTree[i].l == v && segTree[i].r == v) {
    return;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(v <= mid)
    query(LEFT(i), v, ans);
  else
    query(RIGHT(i), v, ans);
}

void SegmentTree::add_range(int i, int l, int r, int val) {
  if(l == segTree[i].l && r == segTree[i].r) {
    segTree[i].v.insert(val);
  } else {
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid) {
      add_range(LEFT(i), l, r, val);
    }
    else if(l > mid) {
      add_range(RIGHT(i), l, r, val);
    }
    else {
      add_range(LEFT(i), l, mid, val);
      add_range(RIGHT(i), mid+1, r, val);
    }
  }
}
