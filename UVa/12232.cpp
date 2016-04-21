#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 20000;
int f[maxn+5], v[maxn+5];
bool vis[maxn+5];
int nums[20];
int n, tot;
char str[100];

int find_set(int a);

bool union_set(int a, int b, int c) {
  //printf("union set %d %d %d\n", a, b, c);
  int fa = find_set(a);
  int fb = find_set(b);
  if(fa == fb) {
    //printf("same parent\n");
    //printf("v[a]^v[b]=%d\n", v[a]^v[b]);
    return (v[a]^v[b]) == c;
  }
  if(fa == n)
    swap(fa, fb);
  f[fa] = fb;
  v[fa] = v[a] ^ v[b] ^ c;
  //printf("set v[%d]=%d\n", fa, v[fa]);
  return true;
}

int find_set(int a) {
  int fa = f[a];
  if(fa != a) {
    f[a] = find_set(fa);
    v[a] ^= v[fa];
  }
  return f[a];
}

void solve() {
  memset(vis, false, sizeof vis);
  int ans = 0;
  for(int i = 0; i < tot; i++) {
    if(!vis[i]) {
      int cnt = 0;
      int root = find_set(nums[i]);
      for(int j = i; j < tot; j++) {
	if(!vis[j] && find_set(nums[j]) == root) {
	  vis[j] = true;
	  cnt++;
	  ans ^= v[nums[j]];
	}
      }
      if(root != n && (cnt & 1)) {
	printf("I don't know.\n");
	return;
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int q;
  int kase = 1;
  while(~scanf("%d%d\n", &n, &q) && (n || q)) {
    printf("Case %d:\n", kase++);
    for(int i = 0; i <= n; i++) {
      f[i] = i;
      v[i] = 0;
    }
    bool ok = true;
    int cnt = 0;
    while(q--) {
      scanf("%s", str);
      if(str[0] == 'I') {
	cnt++;
	getchar();
	gets(str);
	//printf("string is %s\n", str);
	int space = 0;
	for(int i = 0; str[i] != '\0'; i++) {
	  if(str[i] == ' ')
	    space++;
	}
	//printf("space is %d\n", space);
	int a, b, c;
	if(space == 1) {
	  sscanf(str, "%d%d", &a, &c);
	  b = n;
	} else {
	  sscanf(str, "%d%d%d", &a, &b, &c);
	}
	//printf("a = %d b = %d c = %d\n", a, b, c);
	if(!ok)
	  continue;
	if(!union_set(a, b, c)) {
	  printf("The first %d facts are conflicting.\n", cnt);
	  ok = false;
	}
      } else if(str[0] == 'Q') {
	scanf("%d", &tot);
	for(int i = 0; i < tot; i++)
	  scanf("%d", &nums[i]);
	if(!ok)
	  continue;
	solve();
      }
    }
    printf("\n");
  }
  return 0;
}
