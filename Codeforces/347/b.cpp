#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
bool sv[maxn+5];
int vi, n, pos, neg;
char c;

int main() {
  vi = pos = neg = 0;
  scanf("%c ", &c);
  sv[vi++] = true;
  pos++;
  while(scanf("%c ", &c)) {
    if(c == '=')
      break;
    sv[vi] = c == '+';
    sv[vi] ? pos++ : neg++;
    vi++;
    scanf("%c ", &c);
  }
  scanf("%d", &n);
  int minval = pos - n * 1LL * neg;
  int maxval = n * 1LL * pos - neg;
  if(n < minval || n > maxval) {
    printf("Impossible\n");
    return 0;
  } else {
    printf("Possible\n");
    int diff = n - pos + neg;
    for(int i = 0; i < vi; i++) {
      if(i > 0) {
	printf(" %c ", sv[i] ? '+' : '-');
      }
      int m = 1;
      if(sv[i] && diff > 0) {
	m = min(n, 1 + diff);
	printf("%d", m);
	diff -= (m - 1);
      } else if(!sv[i] && diff < 0) {
	m = min(n, 1 - diff);
	printf("%d", m);
	diff += (m - 1);
      } else {
	printf("%d", m);
      }
    }
  }
  printf(" = %d\n", n);
  return 0;
}
