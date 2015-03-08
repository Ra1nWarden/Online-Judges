#include <cstdio>
#include <cstring>
#include <vector>
#define MAXL 300005
#define MAXN 400005
#define MOD 20071027

using namespace std;

char str[MAXL];
int val[MAXN];
int trie[MAXN][26];
int node_n;
char dict[105];
int dp[MAXL];

void insert() {
  int cur = 0;
  int len = strlen(dict);
  for(int i = 0; i < len; i++) {
    if(trie[cur][dict[i] - 'a'] == 0) {
      trie[cur][dict[i] - 'a'] = node_n++;
    }
    cur = trie[cur][dict[i] - 'a'];
  }
  val[cur] = strlen(dict);
}

vector<int> findprefix(int start, int len) {
  int u = 0;
  vector<int> res;
  for(int i = start; i < start + len; i++) {
    u = trie[u][str[i] - 'a'];
    if(u == 0)
      break;
    if(val[u] != 0)
      res.push_back(val[u]);
  }
  return res;
}

int main() {
  int tc = 1;
  while(scanf("%s\n", str) != EOF) {
    int n;
    memset(val, 0, sizeof val);
    memset(trie, 0, sizeof trie);
    node_n = 1;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
      scanf("%s\n", dict);
      insert();
    }
    int l = strlen(str);
    memset(dp, 0, sizeof dp);
    dp[l] = 1;
    for(int i = l - 1; i >= 0; i--) {
      vector<int> prefixv = findprefix(i, l - i);
      for(int j = 0; j < prefixv.size(); j++)
	dp[i] = (dp[i] + dp[i + prefixv[j]]) % MOD;
    }
    printf("Case %d: %d\n", tc++, dp[0]);
  }
  return 0;
}
