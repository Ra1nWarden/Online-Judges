#include <cstdio>
#include <cstring>
#include <queue>
#define MAXPL 25
#define MAXNODE 405

using namespace std;

char pat[MAXPL];
double prob[128];
int n, l;
double dp[MAXNODE][101];
bool dpv[MAXNODE][101];

struct AhoCorasickAutomata {
  int trie[MAXNODE][128];
  bool word[MAXNODE];
  int node_count;
  int f[MAXNODE];
  AhoCorasickAutomata() {
    node_count = 1;
    memset(trie[0], 0 ,sizeof trie[0]);
    memset(word, false, sizeof word);
  }
  void insert(char* s) {
    int len = strlen(s);
    int cur = 0;
    for(int i = 0; i < len; i++) {
      char nextchar = s[i];
      if(trie[cur][nextchar] == 0) {
	trie[cur][nextchar] = node_count++;
	//printf("nextchar is %c node number is %d\n", nextchar, node_count-1);
	memset(trie[node_count-1], 0, sizeof trie[node_count-1]);
      }
      cur = trie[cur][nextchar];
    }
    //printf("setting word[%d] to true\n", cur);
    word[cur] = true;
  }
  void init() {
    queue<int> q;
    f[0] = 0;
    for(int c = 0; c < 128; c++) {
      int u = trie[0][c];
      if(u) {
	f[u] = 0;
	q.push(u);
      }
    }
    while(!q.empty()) {
      int r = q.front();
      q.pop();
      for(int c = 0; c < 128; c++) {
	int u = trie[r][c];
	if(!u) {
	  trie[r][c] = trie[f[r]][c];
	  continue;
	}
	q.push(u);
	int v = f[r];
	while(v && !trie[v][c])
	  v = f[v];
	f[u] = trie[v][c];
	word[u] = word[u] ? true : word[f[u]];
      }
    }
  }
  double func(int cur, int left) {
    //printf("calling func(%d, %d)\n", cur, left);
    if(dpv[cur][left])
      return dp[cur][left];
    if(left == 0) {
      return dp[cur][left] = 1;
    }
    double res = 0.0;
    for(int i = 0; i < 128; i++) {
      if(prob[i] > 0 && !word[trie[cur][i]]) {
	//printf("from %d going to %c\n", cur, i);
	res += prob[i] * func(trie[cur][i], left - 1);
      }
    }
    dpv[cur][left] = true;
    return dp[cur][left] = res;
  }
};



int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 1; et <= tc; et++) {
    AhoCorasickAutomata ac;
    int k;
    scanf("%d\n", &k);
    while(k--) {
      scanf("%s\n", pat);
      ac.insert(pat);
    }
    ac.init();
    scanf("%d\n", &n);
    memset(prob, 254, sizeof prob);
    for(int i = 0; i < n; i++) {
      char c;
      double p;
      scanf("%c %lf\n", &c, &p);
      prob[c] = p;
    }
    scanf("%d\n\n", &l);
    memset(dpv, false, sizeof dpv);
    printf("Case #%d: %.6f\n", et, ac.func(0, l));
  }
  return 0;
}
