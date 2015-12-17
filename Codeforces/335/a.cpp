#include <cstdio>

using namespace std;

int a[3], b[3];

int main() {
  for(int i = 0; i < 3; i++)
    scanf("%d", &a[i]);
  for(int i = 0; i < 3; i++)
    scanf("%d", &b[i]);
  int quota = 0;
  for(int i = 0; i < 3; i++) {
    if(a[i] >= b[i]) {
      quota += (a[i] - b[i]) / 2;
    } else {
      quota -= b[i] - a[i];
    }
  }
  printf("%s\n", quota >= 0 ? "Yes" : "No");
  return 0;
}
