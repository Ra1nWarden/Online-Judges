#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
int v[maxn+5];

int main() {
  memset(v, 0, sizeof v);
  int sum = 0;
  int maxsum = 0;
  for(int i = 0; i < 5; i++) {
    int num;
    scanf("%d", &num);
    sum += num;
    v[num]++;
    if(v[num] == 2 || v[num] == 3) {
      maxsum = max(maxsum, v[num] * num);
    }
  }
  printf("%d\n", sum - maxsum);
  return 0;
}
