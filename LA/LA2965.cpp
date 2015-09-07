#include <cstdio>
#include <map>
#include <cstring>
#define MAXN 30
#define MAXL 1000

using namespace std;

int v[MAXN];
char s[MAXL];
int n;
map<int, int> m;

int bitcount(int num) {
  int ans = 0;
  while(num) {
    if(num & 1)
      ans++;
    num >>= 1;
  }
  return ans;
}

int main() {
  while(~scanf("%d\n", &n)) {
    for(int i = 0; i < n; i++) {
      scanf("%s", s);
      v[i] = 0;
      for(int j = 0; j < strlen(s); j++) {
	v[i] ^= (1 << (s[j] - 'A'));
      }
    }
    m.clear();
    int n1 = n / 2;
    int n2 = n - n1;
    for(int i = 0; i < (1 << n1); i++) {
      int sub = 0;
      for(int j = 0; j < n1; j++) {
	if(i & (1 << j)) {
	  sub ^= v[j];
	}
      }
      if(m.count(sub) == 0 || bitcount(m[sub]) < bitcount(i)) {
	m[sub] = i;
      }
    }
    int ans = 0;
    for(int i = 0; i < (1 << n2); i++) {
      int sub = 0;
      for(int j = 0; j < n2; j++) {
	if(i & (1 << j))
	  sub ^= v[j + n1];
      }
      if(m.count(sub) && bitcount(m[sub]) + bitcount(i) > bitcount(ans)) {
	ans = m[sub] | (i << n1);
      }
    }
    printf("%d\n", bitcount(ans));
    int left = bitcount(ans);
    for(int i = 0; i < n; i++) {
      if(ans & (1 << i)) {
	printf("%d", i + 1);
	left--;
	if(left)
	  printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
