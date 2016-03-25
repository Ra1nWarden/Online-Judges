#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int rv[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  memset(rv, -1, sizeof rv);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    rv[v[i]] = i;
  }
  bool check = true;
  int cur = -1;
  for(int i = 0; i < n; i++) {
    //printf("i=%d cur=%d\n", i, cur);
    int num;
    scanf("%d", &num);
    if(num == 0)
      continue;
    int idx = rv[num];
    if(cur == -1) {
      cur = idx;
    } else {
      for(int j = (cur + 1) % n; j != idx; j = (j + 1) % n) {
	//printf("j=%d\n", j);
	if(v[j] == 0)
	  continue;
	else {
	  check = false;
	  break;
	}
      }
      if(!check)
	break;
      cur = idx;
    }
  }
  printf("%s\n", check ? "YES" : "NO");
  return 0;
}
