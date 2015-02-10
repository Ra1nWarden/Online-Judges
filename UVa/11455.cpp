#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  int v[4];
  for(int i= 0; i < tc; i++) {
    scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
    sort(v, v+4);
    if(v[0] == v[1] && v[2] == v[3]) {
      if(v[1] == v[2])
	printf("square\n");
      else
	printf("rectangle\n");
    } else {
      if(v[0] + v[1] + v[2] > v[3])
	printf("quadrangle\n");
      else
	printf("banana\n");
    }
  }
  return 0;
}
