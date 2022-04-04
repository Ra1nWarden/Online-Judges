#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 12;
const int maxm = 500000;
const int maxk = 100;
int v[maxn+5];
map<int, int> mv;
int n, m, q;
int wu[(1 << maxn) + 5];
char num[15];
int memo[(1 << maxn) + 5][maxk + 5];

int scan_num() {
  scanf("%s", num);
  int val = 0;
  for(int i = 0; i < n; i++) {
    val <<= 1;
    if(num[i] == '1') {
      val |= 1;
    }
  }
  return val;
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < m; i++) {
    int val = scan_num();
    if(mv.count(val)) {
      mv[val]++;
    } else {
      mv[val] = 1;
    }
  }

  for(int mask = 0; mask < (1 << n); mask++) {
    wu[mask] = 0;
    for(int i = 0; i < n; i++) {
      if(!((1 << i) & mask)) {
	wu[mask] += v[n-1-i];
      }
    }
  }

  memset(memo, -1, sizeof memo);

  while(q--) {
    int val = scan_num();
    int k;
    scanf("%d", &k);
    if(memo[val][k] == -1) {
      for(map<int, int>::iterator itr = mv.begin(); itr != mv.end(); itr++) {
	int res = wu[val ^ itr->first];
	if(res > maxk)
	  continue;
	if(memo[val][res] == -1) {
	  memo[val][res] = itr->second;
	} else {
	  memo[val][res] += itr->second;
	}
      }
      int acc = 0;
      for(int i = 0; i <= maxk; i++) {
	if(memo[val][i] != -1) {
	  acc += memo[val][i];
	}
	memo[val][i] = acc;
      }
    }
    printf("%d\n", memo[val][k]);
  }
  
  return 0;
}
