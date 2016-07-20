#include <cstdio>

using namespace std;

const int maxn = 10;
char v[maxn+5];
int ok[10][4] = {{1, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 1}};
int n;

int main() {
  scanf("%d\n%s", &n, v);
  bool valid = true;
  for(int i = 0; i < 4; i++) {
    bool cur = true;
    for(int j = 0; j < n; j++) {
      if(!ok[v[j] - '0'][i]) {
	cur = false;
	break;
      }
    }
    if(cur) {
      valid = false;
      break;
    }
  }
  printf("%s\n", valid ? "YES" : "NO");
  return 0;
}
