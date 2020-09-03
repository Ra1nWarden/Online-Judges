#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int v[maxn+5];
int n;
int o = 0, t = 0, to = 0, tot = 0, ot = 0, oto = 0, otot = 0;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);

  for(int i = 0; i < n; i++) {
    if(v[i] == 1) {
      o++;
      int update = 0;
      if(ot) {
	update = ot + 1;
      }
      if(oto) {
	update = max(update, oto+1);
      }
      oto = update;
      update = 0;
      if(t) {
	update = t + 1;
      }
      if(to) {
	update = max(update, to+1);
      }
      to = update;
    } else {
      t++;
      int update = 0;
      if(o) {
	update = o + 1;
      }
      if(ot) {
	update = max(update, ot + 1);
      }
      ot = update;
      update = 0;
      if(oto) {
	update = max(update, oto + 1);
      }
      if(otot) {
	update = max(update, otot + 1);
      }
      otot = update;
      update = 0;
      if(to) {
	update = to + 1;
      }
      if(tot) {
	update = max(update, tot + 1);
      }
      tot = update;
    }
  }
  
  printf("%d\n", max(max(max(max(o, ot), max(oto, otot)), max(t, to)), tot));
  
  return 0;
}
