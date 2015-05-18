#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <map>
#define MAXN 105

using namespace std;

int n;
char cards[MAXN][5];
map<char, int> m;
map<int, string> mm;
bool matchv[1050];

int main() {
  scanf("%d", &n);
  m['R'] = 0;
  m['G'] = 1;
  m['B'] = 2;
  m['Y'] = 3;
  m['W'] = 4;
  for(int i = 0; i < n; i++) {
    scanf("%s", cards[i]);
  }
  int ans = 10;
  for(int i = 0; i < (1 << 10) - 1; i++) {
    int guesscount = 0;
    for(int j = 0; j < 10; j++) {
      if((i & (1 << j)) != 0)
	guesscount++;
    }
    if(guesscount >= ans)
      continue;
    bool ok = true;
    memset(matchv, false, sizeof matchv);
    mm.clear();
    for(int j = 0; j < n; j++) {
      int bitmask = 0;
      int colormask = m[cards[j][0]];
      if(((1 << colormask) & i) != 0) {
	bitmask = (bitmask | (1 << colormask));
      }
      int numbermask = cards[j][1] - '1' + 5;
      if(((1 << numbermask) & i) != 0) {
	bitmask = (bitmask | (1 << numbermask));
      }
      string key(cards[j]);
      if(matchv[bitmask]) {
	if(mm[bitmask] != key) {
	  ok = false;
	  break;
	}
      }
      matchv[bitmask] = true;
      mm[bitmask] = key;
    }
    if(ok) {
      ans = min(ans, guesscount);
    }
  }
  printf("%d\n", ans);
  return 0;
}
