#include <cstring>
#include <cstdio>

using namespace std;

const int maxl = 100000;
char dirs[maxl+5];
int delta[maxl+5];
bool visited[maxl+5];
int n;

int main() {
  scanf("%d\n", &n);
  scanf("%s\n", dirs);
  for(int i = 0; i < n; i++)
    scanf("%d", &delta[i]);
  memset(visited, false, sizeof visited);
  int pos = 0;
  while(!visited[pos]) {
    visited[pos] = true;
    if(dirs[pos] == '<') {
      pos -= delta[pos];
    } else if(dirs[pos] == '>') {
      pos += delta[pos];
    }
    if(pos < 0 || pos >= n)
      break;
  }
  printf("%s\n", (pos < 0 || pos >= n) ? "FINITE" : "INFINITE");
  return 0;
}
