#include <cstdio>
#include <cstring>
#define MAXN 5055

using namespace std;


bool possible(int w, int m) {
  if(m == 0)
    return true;
  if(m % w != 0) {
    int r = m % w;
    if(r == 1) {
      return w == 2 ? possible(w, m-1) || possible(w, m+1) : possible(w, m-1);
    } else if(r == w - 1) {
      return possible(w, m+1);
    } else {
      return false;
    }
  }
  return possible(w, m / w);
}

int main() {
  int w, m;
  scanf("%d %d", &w, &m);
  if(possible(w, m))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
