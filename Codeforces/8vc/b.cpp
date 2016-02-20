#include <cstdio>

using namespace std;

const int maxn = 200;
char str[maxn+5];
int n;

int cnt[3];

bool check(int i) {
  int j = (i + 1) % 3;
  int k = (i + 2) % 3;
  if(cnt[j] && cnt[k])
    return true;
  if(cnt[j] == 0 && cnt[k] == 0)
    return true;
  if(cnt[j])
    return cnt[j] > 1 && cnt[i];
  else
    return cnt[k] > 1 && cnt[i];
}

int main() {
  scanf("%d\n%s", &n, str);
  for(int i = 0; i < n; i++) {
    if(str[i] == 'B') {
      cnt[0]++;
    } else if(str[i] == 'G') {
      cnt[1]++;
    } else if(str[i] == 'R') {
      cnt[2]++;
    }
  }
  if(check(0))
    printf("B");
  if(check(1))
    printf("G");
  if(check(2))
    printf("R");
  printf("\n");
  return 0;
}
