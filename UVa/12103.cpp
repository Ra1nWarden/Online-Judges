#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 26;
char str[maxn+5];
bool vis[maxn+5];
int perm[maxn+5];

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", str);
    memset(vis, false, sizeof vis);
    memset(perm, 0, sizeof perm);
    for(char c = 'A'; c <= 'Z'; c++) {
      char itr = c;
      int len = 0;
      while(!vis[itr - 'A']) {
	vis[itr - 'A'] = true;
	itr = str[itr - 'A'];
	len++;
      }
      if(len)
	perm[len]++;
    }
    bool ok = true;
    for(int i = 2; i <= maxn; i += 2) {
      if(perm[i] % 2) {
	ok = false;
	break;
      }
    }
    printf("%s\n", ok ? "Yes" : "No");
  }
  return 0;
}
