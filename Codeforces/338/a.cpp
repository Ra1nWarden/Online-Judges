#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
bool ok[maxn+5];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  memset(ok, false, sizeof ok);
  int cnt = 0;
  while(n--) {
    int num;
    scanf("%d", &num);
    while(num--) {
      int bulb;
      scanf("%d", &bulb);
      if(!ok[bulb]) {
	cnt++;
      }
      ok[bulb] = true;
    }
  }
  printf("%s\n", cnt < m ? "NO" : "YES");
  return 0;
}
