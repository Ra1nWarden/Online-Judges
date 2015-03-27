#include <cstdio>
#include <algorithm>

using namespace std;

int v[4];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  if(n == 0) {
    printf("YES\n");
    printf("1\n1\n3\n3\n");
  } else if(n == 1) {
    printf("YES\n");
    printf("%d\n%d\n%d\n", v[0], 3*v[0], 3*v[0]);
  } else if(n == 2) {
    if(v[1] > v[0] * 3) {
      printf("NO\n");
    } else {
      printf("YES\n");
      printf("%d\n%d\n", v[0] * 3, v[0] * 4 - v[1]);
    }
  } else if(n == 3) {
    if(v[2] > v[0] * 3) {
      printf("NO\n");
    } else {
      if(v[1] + v[2] == v[0] * 4) {
	printf("YES\n");
	printf("%d\n", 3*v[0]);
      } else if(v[2] == v[0] * 3) {
	printf("YES\n");
	printf("%d\n", 4 * v[0] - v[1]);
      } else if(v[2] % 3 == 0 && v[1] + v[0] == (v[2] / 3) * 4) {
	printf("YES\n");
	printf("%d\n", v[2] / 3);
      } else {
	printf("NO\n");
      }
    }
  } else {
    if(v[3] = 3 * v[0] && v[1] + v[2] == v[0] + v[3])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
