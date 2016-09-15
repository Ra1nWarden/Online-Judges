#include <cstdio>

using namespace std;

const int maxn = 1000;
char seats[maxn][6];
int n;

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s\n", seats[i]);
  }
  bool ok = false;
  for(int i = 0; i < n; i++) {
    if(seats[i][0] == 'O' && seats[i][1] == 'O') {
      seats[i][0] = seats[i][1] = '+';
      ok = true;
      break;
    }
    if(seats[i][3] == 'O' && seats[i][4] == 'O') {
      seats[i][3] = seats[i][4] = '+';
      ok = true;
      break;
    }
  }
  printf("%s\n", ok ? "YES" : "NO");
  if(ok) {
    for(int i = 0; i < n; i++) {
      printf("%s\n", seats[i]);
    }
  }
  return 0;
}
