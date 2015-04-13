#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#define MAXN 200005

using namespace std;

map<int, vector<int> > m;
int C[MAXN];
int n;

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int d) {
  while(x <= n) {
    C[x] += d;
    x += lowbit(x);
  }
}

int ans[MAXN];
int ni;

int main() {
  scanf("%d", &n);
  memset(C, 0, sizeof C);
  m.clear();
  for(int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    x++;
    m[x].push_back(i);
    add(x, 1);  
  }

  int cur = 1;
  ni = 0;
  for(int i = 0; i < n; i++) {
    //printf("i=%d cur=%d\n", i, cur);
    if(m[cur].empty()) {
      //printf("%d is empty!\n", cur);
      printf("Impossible\n");
      return 0;
    }
    ans[ni++] = m[cur].back();
    m[cur].pop_back();
    add(cur, -1);
    //printf("sum[%d]=%d\n", cur, sum(cur));
    if(cur == 1 || cur == 2 || sum(cur) == 0)
      cur++;
    else if(!m[cur - 2].empty()) {
      cur-=2;
    } else {
      cur++;
    }
  }
  printf("Possible\n");
  for(int i = 0; i < n; i++) {
    if(i != 0)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
