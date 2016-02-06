#include <cstdio>

using namespace std;

const int maxn = 1000;
int v1[maxn], v2[maxn];
int v1i, v2i;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    v1i = v2i = 0;
    for(int i = 1; i * i <= a; i++) {
      if(a % i == 0)
	v1[v1i++] = i;
    }
    for(int i = 1; i * i <= c; i++) {
      if(c % i == 0)
	v2[v2i++] = i;
    }
    bool ok = false;
    for(int i = 0; i < v1i && !ok; i++) {
      for(int j = 0; j < v2i && !ok; j++) {
	int m = v1[i], n = a / v1[i];
	int s = v2[j], t = c / v2[j];
	if(m * t + n * s == b || m * s + n * t == b)
	  ok = true;
      }
    }
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}
