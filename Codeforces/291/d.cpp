#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100005
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)|1)
#define MID(x, y) ((x+y)>>1)

using namespace std;

int n, m, k;

struct Node {
  int l, r;
  int maxv[5];
};

Node segTree[MAXN * 4];
int v[MAXN][5];

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  if(l == r) {
    for(int j = 0; j < m; j++) {
      segTree[i].maxv[j] = v[l][j];
    }
    return;
  }
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r) + 1, r);
  for(int j = 0; j < m; j++) {
    segTree[i].maxv[j] = max(segTree[LEFT(i)].maxv[j], segTree[RIGHT(i)].maxv[j]);
  }
}

vector<int> query(int i, int l, int r) {
  vector<int> res;
  if(segTree[i].l == l && segTree[i].r == r) {
    for(int j = 0; j < m; j++) {
      res.push_back(segTree[i].maxv[j]);
    }
    return res;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid)
    return query(LEFT(i), l, r);
  else if (l > mid)
    return query(RIGHT(i), l , r);
  else {
    vector<int> lres = query(LEFT(i), l, mid);
    vector<int> rres = query(RIGHT(i), mid+1, r);
    for(int j = 0; j < lres.size(); j++) {
      res.push_back(max(lres[j], rres[j]));
    }
    return res;
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  build(1, 0, n - 1);
  int maxlength = -1;
  vector<int> maxres;

  // for(int i = 0; i < n; i++) {
  //   if(i + maxlength > n)
  //     break;
  //   for(int j = n - 1; j >= (maxlength < 0 ? i : i + maxlength); j--) {
  //     vector<int> res = query(1, i, j);
  //     int val = 0;
  //     for(int k = 0; k < res.size(); k++) {
  // 	val += res[k];
  //     }
  //     if(val <= k) {
  // 	if((j - i + 1) > maxlength) {
  // 	  maxlength = j - i + 1;
  // 	  maxres = res;
  // 	}
  // 	break;
  //     }
  //   }
  // }

  int start = 0;
  int end = 0;
  while(true) {
    vector<int> res = query(1, start, end);
    int val = 0;
    for(int i = 0; i < res.size(); i++) {
      val += res[i];
    }
    if(val <= k) {
      if(end - start + 1 > maxlength) {
	maxlength = end - start + 1;
	maxres = res;
      }
      end++;
    } else {
      start++;
    }
    if(start > end)
      end = start;
    if(end == n)
      break;
  }

  if(maxlength != -1) {
    for(int i = 0; i < maxres.size(); i++) {
      if(i != 0)
	printf(" ");
      printf("%d", maxres[i]);
    }
  } else {
    for(int i = 0; i < m; i++) {
      if(i != 0)
	printf(" ");
      printf("0");
    }
  }
  printf("\n");
  return 0;
}
