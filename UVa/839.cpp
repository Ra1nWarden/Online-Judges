#include <cstdio>

using namespace std;

bool solve(int& w) {
  int w1, d1, w2, d2;
  scanf("%d %d %d %d", &w1, &d1, &w2, &d2);
  bool b1 = true;
  bool b2 = true;
  if(!w1)
    b1 = solve(w1);
  if(!w2)
    b2 = solve(w2);
  w = w1 + w2;
  return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main() {
  int tc, w;
  scanf("%d", &tc);
  while(tc--) {
    if(solve(w))
      printf("YES\n");
    else
      printf("NO\n");
    if(tc)
      printf("\n");
  }
  return 0;
}
