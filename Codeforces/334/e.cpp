#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int n, k;
map<int, int> memo;

int sg(int num) {
  if(memo.count(num))
    return memo[num];
  if(num == 0)
    return 0;
  if(num % 2 && num > 3)
    return 0;
  int vis[3];
  memset(vis, false, sizeof vis);
  int next = sg(num - 1);
  if(next < 3)
    vis[next] = true;
  if(num % 2 == 0) {
    if(k % 2 == 0) {
      vis[0] = true;
    } else {
      int sub = sg(num / 2);
      if(sub < 3)
	vis[sub] = true;
    }
  }
  for(int i = 0; i < 3; i++) {
    if(!vis[i])
      return memo[num] = i;
  }
}

int main() {
  scanf("%d%d", &n, &k);
  int nim = 0;
  for(int i = 0; i < n; i++) {
    int state;
    scanf("%d", &state);
    nim ^= sg(state);
  }
  if(nim == 0) {
    printf("Nicky\n");
  } else {
    printf("Kevin\n");
  }
  return 0;
}
