#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100;
int v[maxn+5][maxn+5];
int n, m;
int row[maxn+5];
int col[maxn+5];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &row[i]);
  for(int i = 0; i < m; i++)
    scanf("%d", &col[i]);

  memset(v, 0, sizeof v);

  bool yes = true;
  for(int i = 0; i < 31; i++) {
    vector<int> r, c;
    int mask = 1 << i;
    for(int j = 0; j < n; j++) {
      int cur = row[j] & mask;
      if(cur)
	r.push_back(j);
    }
    for(int j = 0; j < m; j++) {
      int cur = col[j] & mask;
      if(cur)
	c.push_back(j);
    }

    if((r.size() & 1) != (c.size() & 1)) {
      yes = false;
      break;
    }

    for(int j = 0; j < min(r.size(), c.size()); j++) {
      v[r[j]][c[j]] |= (1 << i);
    }

    for(int j = min(r.size(), c.size()); j < max(r.size(), c.size()); j++) {
      if(j >= r.size()) {
	v[0][c[j]] |= (1 << i);
      } else {
	v[r[j]][0] |= (1 << i);
      }
    }
  }
  if(!yes) {
    printf("NO\n");
  } else {
    printf("YES\n");
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	if(j)
	  printf(" ");
	printf("%d", v[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
