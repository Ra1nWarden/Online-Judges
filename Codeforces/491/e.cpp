#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

char seen[20];
int cnt[10];
int len;
int cur[10];
set<long long> vis;

long long perm(int num) {
  long long ans = 1;
  while(num) {
    ans *= num;
    num--;
  }
  return ans;
}

int main() {
  scanf("%s", seen);
  len = strlen(seen);
  memset(cnt, 0, sizeof cnt);
  for(int i = 0; i >= 0; i++) {
    if(!seen[i]) {
      break;
    }
    cnt[seen[i] - '0']++;
  }

  long long ans = 0;
  
  for(int mask = 1; mask < (1LL << len); mask++) {
    memset(cur, 0, sizeof cur);
    int digit = 0;
    for(int idx = 0; idx < len; idx++) {
      if((1 << idx) & mask) {
	cur[seen[idx] - '0']++;
	digit++;
      }
    }
    bool ok = true;
    for(int i = 0; i < 10; i++) {
      if(cnt[i] && !cur[i]) {
	ok = false;
	break;
      }
    }

    if(!ok) {
      continue;
    }

    long long num = 0;
    for(int i = 9; i >= 0; i--) {
      if(cur[i]) {
	for(int j = 0; j < cur[i]; j++) {
	  num = num * 10 + i;
	}
      }
    }

    if(vis.count(num)) {
      continue;
    }

    vis.insert(num);

    long long subans = perm(digit);
    for(int i = 0; i < 10; i++) {
      if(cur[i]) {
	subans /= perm(cur[i]);
      }
    }

    if(cur[0]) {
      cur[0]--;
      long long subtract = perm(digit - 1);
      for(int i = 0; i < 10; i++) {
	if(cur[i]) {
	  subtract /= perm(cur[i]);
	}
      }
      subans -= subtract;
    }

    ans += subans;
  }

  printf("%I64d\n", ans);

  return 0;
}
