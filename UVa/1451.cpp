#include <cstdio>
#define MAXN 100005

using namespace std;

char v[MAXN];
int n, l;
int sum[MAXN], p[MAXN];

int cmp(int x1, int x2, int x3, int x4) {
  //printf("called cmp(%d %d %d %d)\n", x1, x2, x3, x4);
  return (sum[x2] - sum[x1 - 1]) * (x4 - x3 + 1) - (sum[x4] - sum[x3 - 1]) * (x2 - x1 + 1);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d %s", &n, &l, v+1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
      sum[i] = sum[i-1] + v[i] - '0';
    int ansL = 0;
    int ansR = l;
    int i = 0;
    int j = 0;
    for(int t = l; t <= n; t++) {
      // if(j - i > 1)
      // 	printf("before while\n");
      while(j - i > 1 && cmp(p[j-2], t-l, p[j-1], t-l) >= 0) // Remove concave points before inserting new one. Since sum is not decreasing, just use t-l to refer to the last element. In this case t-l == p[j-1]. It is not t-l+1 or t because of this.
	j--;
      p[j++] = t-l+1;
      while(j - i > 1 && cmp(p[i], t, p[i+1], t) <= 0)
	i++;

      int c = cmp(p[i], t, ansL, ansR);
      if(c > 0 || c == 0 && t - p[i] < ansR - ansL) {
	ansL = p[i];
	ansR = t;
      }
    }
    printf("%d %d\n",ansL, ansR);
  }
  return 0;
}
