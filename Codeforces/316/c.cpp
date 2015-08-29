#include <cstdio>
#define MAXN 300005

using namespace std;

int n, m;
char s[MAXN];

int main() {
  scanf("%d %d\n", &n, &m);
  scanf("%s", s);
  int segs = 0;
  int length = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '.') {
      length++;
      segs++;
      if(i > 0 && s[i-1] == '.')
	segs--;
    }
  }
  for(int i = 0; i < m; i++) {
    int pos;
    char c;
    scanf("%d %c", &pos, &c);
    if(c == '.') {
      if(s[pos-1] != '.') {
	length++;
	segs++;
	if(pos > 1 && s[pos-2] == '.')
	  segs--;
	if(pos < n && s[pos] == '.')
	  segs--;
      }
    } else {
      if(s[pos-1] == '.') {
	length--;
	segs--;
	if(pos > 1 && s[pos-2] == '.')
	  segs++;
	if(pos < n && s[pos] == '.')
	  segs++;
      }
    }
    s[pos-1] = c;
    printf("%d\n", length - segs);
  }
  return 0;
}
