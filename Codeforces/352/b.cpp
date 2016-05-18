#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;
char str[maxn+5];
const int maxc = 26;
bool visited[maxc];

int main() {
  int n;
  scanf("%d\n", &n);
  scanf("%s\n", str);
  if(n > 26)
    printf("-1\n");
  else {
    memset(visited, false, sizeof visited);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(visited[str[i] - 'a']) {
	ans++;
      } else {
	visited[str[i] - 'a'] = true;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
