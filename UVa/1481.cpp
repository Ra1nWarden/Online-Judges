#include <cstdio>
#include <cstring>
#define MAXN 3005

using namespace std;

int v[MAXN];
int m[MAXN];
bool visited[MAXN];
int n;

int main() {
  while(~scanf("%d", &n) && n) {
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      m[num] = i;
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      memset(visited, false, sizeof visited);
      int cluster = 0;
      for(int j = i; j < n; j++) {
	cluster++;
	int pos = m[v[j]];
	visited[pos] = true;
	if(j > i) {
	  if(pos > 0 && visited[pos-1])
	    cluster--;
	  if(pos < n - 1 && visited[pos+1])
	    cluster--;
	  if(cluster == 1)
	    ans++;
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
