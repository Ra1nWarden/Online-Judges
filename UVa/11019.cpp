#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#define MAXS 1005
#define MAXP 105
#define MAXNODE 10005

using namespace std;

int n, m;
char str[MAXS][MAXS];
int count[MAXS][MAXS];
int x, y;
char pat[MAXP][MAXP];
bool match[MAXS][MAXS][MAXP];
int res;

struct AhoCorasickAutomata {
  int trie[MAXNODE][128];
  int next_node;
  vector<int> val[MAXNODE];
  int f[MAXNODE];
  int last[MAXNODE];
  AhoCorasickAutomata() {
    next_node = 1;
    memset(trie[0], 0, sizeof trie[0]);
  }
  void insert(char* p, int v) {
    int len = strlen(p);
    int cur = 0;
    for(int i = 0; i < len; i++) {
      int c = p[i];
      if(trie[cur][c] == 0) {
	trie[cur][c] = next_node++;
	memset(trie[next_node-1], 0, sizeof trie[next_node-1]);
      }
      cur = trie[cur][c];
    }
    val[cur].push_back(v);
  }
  void init() {
    queue<int> q;
    f[0] = 0;
    for(int i = 0; i < 128; i++) {
      int u = trie[0][i];
      if(u) {
	q.push(u);
	f[u] = 0;
      }
    }
    while(!q.empty()) {
      int v = q.front();
      q.pop();
      for(int i = 0; i < 128; i++) {
	int u = trie[v][i];
	if(!u) {
	  trie[v][i] = trie[f[v]][i];
	  continue;
	}
	q.push(u);
	int r = f[v];
	while(r && !trie[r][i])
	  r = f[r];
	f[u] = trie[r][i];
	last[u] = val[f[u]].size() > 0 ? f[u] : last[f[u]];
      }
    } 
  }
  void find(char* s, int row) {
    int len = strlen(s);
    int cur = 0;
    for(int i = 0; i < len; i++) {
      cur = trie[cur][s[i]];
      if(!val[cur].empty()) {
	int add = cur;
	while(add != 0) {
	  for(int j = 0; j < val[add].size(); j++) {
	    //printf("setting %d %d %d to true\n", row, i, j);
	    if(row - val[add][j] > -1) {
	      count[row - val[add][j]][i]++;
	      if(count[row - val[add][j]][i] == x)
		res++;
	    }
	  }
	  add = last[add];
	}
      } else if(last[cur]) {
	int add = last[cur];
	while(add != 0) {
	  for(int j = 0; j < val[add].size(); j++) {
	    //printf("setting %d %d %d to true\n", row, i, j);
	     if(row - val[add][j] > -1) {
	      count[row - val[add][j]][i]++;
	      if(count[row - val[add][j]][i] == x)
		res++;
	    }
	  }
	  add = last[add];
	}
      }
    }
  }
};

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    AhoCorasickAutomata ac;
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; i++) {
      scanf("%s\n", str[i]);
    }
    scanf("%d %d\n", &x, &y);
    for(int i = 1; i <= x; i++) {
      scanf("%s\n", pat[i]);
      ac.insert(pat[i], i);
    }
    ac.init();
    memset(count, 0, sizeof count);
    res = 0;
    for(int i = 1; i <= n; i++) {
      ac.find(str[i], i);
    }
    printf("%d\n", res);
  }
  return 0;
}
