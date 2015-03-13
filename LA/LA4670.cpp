#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#define MAXPL 75
#define MAXNODE 10505
#define MAXL 1000005

using namespace std;

int n;
char pattern[151][MAXPL];
char str[MAXL];
int counter[151];

struct AhoCorasickAutomata {
  int node_count;
  int trie[MAXNODE][26];
  int val[MAXNODE];
  int f[MAXNODE];
  int last[MAXNODE];
  AhoCorasickAutomata() {
    memset(trie[0], 0, sizeof trie[0]);
    memset(val, 0, sizeof val);
    node_count = 1;
  }
  void insert(char* pat, int v) {
    int len = strlen(pat);
    int cur = 0;
    for(int i = 0; i < len; i++) {
      char curchar = pat[i];
      if(trie[cur][curchar - 'a'] == 0) {
	trie[cur][curchar - 'a'] = node_count++;
	memset(trie[node_count - 1], 0, sizeof trie[node_count - 1]);
      }
      cur = trie[cur][curchar - 'a'];
    }
    val[cur] = v;
  }
  void init() {
    queue<int> q;
    f[0] = 0;
    for(int c = 0; c < 26; c++) {
      int u = trie[0][c];
      if(u) {
	f[u] = 0;
	q.push(u);
	last[u] = 0;
      }
    }
    while(!q.empty()) {
      int r = q.front();
      q.pop();
      for(int c = 0; c < 26; c++) {
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
	last[u] = val[f[u]] ? f[u] : last[f[u]];
      }
    }
  }
  void find(char* s) {
    int len = strlen(s);
    int j = 0;
    for(int i = 0; i < len; i++) {
      j = trie[j][s[i] - 'a'];
      if(val[j]) {
	int add = j;
	while(add != 0) {
	  counter[val[add]]++;
	  add = last[add];
	}	
      } else if(last[j]) {
	int add = last[j];
	while(add != 0) {
	  counter[val[add]]++;
	  add = last[add];
	}
      }
    }
  }
};

int main() {
  while(scanf("%d\n", &n) != EOF && n) {
    AhoCorasickAutomata ac;
    for(int i = 1; i <= n; i++) {
      scanf("%s\n", pattern[i]);
      ac.insert(pattern[i], i);
    }
    ac.init();
    scanf("%s\n", str);
    int len = strlen(str);
    memset(counter, 0, sizeof counter);
    ac.find(str);
    vector<int> res;
    int maxval = 0;
    for(int i = 1; i <= n; i++) {
      if(counter[i] > maxval) {
	res.clear();
	maxval = counter[i];
	res.push_back(i);
      } else if(counter[i] == maxval) {
	res.push_back(i);
      }
    }
    printf("%d\n", maxval);
    for(int i = 0; i < res.size(); i++) {
      printf("%s\n", pattern[res[i]]);
    }
  }
  return 0;
}
