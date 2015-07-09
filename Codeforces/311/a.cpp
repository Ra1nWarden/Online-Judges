#include <cstdio>

using namespace std;

int v[3][2];
int ans[3];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < 3; i++)
    scanf("%d %d", &v[i][0], &v[i][1]);
  int sum = v[0][0] + v[1][0] + v[2][0];
  ans[0] = v[0][0];
  ans[1] = v[1][0];
  ans[2] = v[2][0];
  while(sum < n) {
    if(ans[0] < v[0][1]) {
      ans[0]++;
    } else if(ans[1] < v[1][1]) {
      ans[1]++;
    } else {
      ans[2]++;
    }
    sum++;
  }
  printf("%d %d %d\n", ans[0], ans[1], ans[2]);
  return 0;
}
