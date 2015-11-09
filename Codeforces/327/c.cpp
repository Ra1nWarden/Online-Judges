#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 500000;
bool v[maxn];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    v[i] = num == 1;
  }
  int a = -1;
  int b = -1;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    bool stable = i == 0 || i == n-1 || v[i] == v[i-1] || v[i] == v[i+1];
    if(!stable) {
      if(a == -1) {
	a = b = i;
      } else {
	b = i;
      }
    } else {
      if(a != -1) {
	if(v[a-1] == v[b+1]) {
	  for(int j = a ; j <= b; j++)
	    v[j] = v[a-1];
	} else {
	  for(int j = a; j <= (a + b) / 2; j++)
	    v[j] = v[a-1];
	  for(int j = (a + b) / 2 + 1; j <= b; j++)
	    v[j] = v[b+1];
	}
	ans = max(ans, (b - a + 2) / 2);
      }
      a = b = -1;
    }
  }
  printf("%d\n", ans);
  for(int i = 0; i < n; i++) {
    if(i > 0)
      printf(" ");
    printf("%d", v[i] ? 1 : 0);
  }
  printf("\n");
  return 0;
}
