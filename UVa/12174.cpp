#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

using namespace std;

int s, n, v[MAXN*3], cnt[MAXN], ok[MAXN*2];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &s, &n);
    memset(v, -1, sizeof v);
    memset(cnt, 0, sizeof cnt);
    memset(ok, false, sizeof ok);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i+s]);
    }
    int counter = 0;
    // starting points
    ok[0] = true;
    for(int i = 1; i < s + n; i++) {
      if(i+s-1 < s + n) {
	int addnum = v[i + s - 1];
	if(cnt[addnum] == 0) {
	  counter++;
	}
	//printf("adding %d\n", addnum);
	cnt[addnum]++;
      }
      if(i > s) {
	int removenum = v[i-1];
	if(cnt[removenum] == 1) {
	  counter--;
	}
	//printf("removing %d\n", removenum);
	cnt[removenum]--;
      }
      //printf("i=%d counter=%d\n", i, counter);
      if(i < s) {
	//printf("i<s compare %d against %d\n", counter, i);
	ok[i] = counter == min(i, n);
      } else if(i <= n){
	//printf("i <= n - s compare %d against %d\n", counter, s);
	ok[i] = counter == s;
      } else {
	//printf("else branch compare %d against %d\n", counter, n + s - i);
	ok[i] = counter == n + s - i;
      }
    }
    int ans = 0;
    for(int i = 0; i < s; i++) {
      if(ok[i]) {
	bool sol = true;
	for(int j = i + s; j < n+s; j += s) {
	  if(!ok[j]) {
	    sol = false;
	    break;
	  }
	}
	if(sol)
	  ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
