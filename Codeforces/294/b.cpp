#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

int v[MAXN], v1[MAXN], v2[MAXN];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v, v+n);
  for(int i = 0; i < n - 1; i++) {
    scanf("%d", &v1[i]);
  }
  sort(v1, v1+n-1);
  bool found = false;
  for(int i = 0; i < n-1; i++) {
    if(v1[i] != v[i]) {
      printf("%d\n", v[i]);
      found = true;
      break;
    }
  }
  if(!found)
    printf("%d\n", v[n-1]);
  for(int i = 0; i < n - 2; i++) {
    scanf("%d", &v2[i]);
  }
  sort(v2, v2+n-2);
  found = false;
  for(int i= 0; i <  n -2; i++) {
    if(v2[i] != v1[i]) {
      printf("%d\n", v1[i]);
      found = true;
      break;
    }
  }
  if(!found)
    printf("%d\n", v1[n-2]);
  return 0;
}
