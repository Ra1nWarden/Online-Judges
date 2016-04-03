#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 50;
int p[maxn+5];
int t[maxn+5];
int n, c;

int main() {
  scanf("%d%d", &n, &c);
  for(int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &t[i]);
  }
  int a_score = 0, b_score = 0;
  int time = 0;
  for(int i = 0; i < n; i++) {
    time += t[i];
    a_score += max(0, p[i] - time * c);
  }
  time = 0;
  for(int i = n - 1; i >= 0; i--) {
    time += t[i];
    b_score += max(0, p[i] - time * c);
  }
  if(a_score == b_score) {
    printf("Tie\n");
  } else if(a_score > b_score) {
    printf("Limak\n");
  } else {
    printf("Radewoosh\n");
  }
  return 0;
}
