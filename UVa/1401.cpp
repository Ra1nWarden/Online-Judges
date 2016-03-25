#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 300000;
const int mod = 20071027;
char str[maxl+5];
char word[105];
int dp[maxl+5];

struct Trie {
  int trie[400000][26];
  int val[400000];
  int nextnode;
  Trie() {}
  void init();
  // Insert word w wiht value v
  void insert(char* w, int v);
};

Trie trie;

int f(int idx) {
  if(dp[idx] != -1) {
    return dp[idx];
  }
  if(str[idx] == 0) {
    return 1;
  }
  int ans = 0;
  int cur = 0;
  for(int i = idx; i < idx + 100; i++) {
    char nextchar = str[i];
    if(nextchar == 0) {
      break;
    }
    cur = trie.trie[cur][nextchar - 'a'];
    if(cur == 0)
      break;
    else if(trie.val[cur]) {
      ans = (ans + f(i + 1)) % mod;
    }
  }
  return dp[idx] = ans;
}

int main() {
  int kase = 1;
  while(scanf("%s\n", str) != EOF) {
    trie.init();
    memset(dp, -1, sizeof dp);
    int s;
    scanf("%d\n", &s);
    for(int i = 0; i < s; i++) {
      scanf("%s\n", word);
      trie.insert(word, 1);
    }
    printf("Case %d: %d\n", kase++, f(0));
  }
  return 0;
}

void Trie::init() {
  nextnode = 1;
  memset(trie[0], 0, sizeof trie[0]);
}

void Trie::insert(char* w, int v) {
  int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    int nextchar = w[i];
    if(trie[cur][nextchar - 'a'] == 0) {
      memset(trie[nextnode], 0, sizeof trie[nextnode]);
      trie[cur][nextchar - 'a'] = nextnode;
      val[nextnode] = 0; // Default value along the way: 0 in this case
      nextnode++;
    }
    cur = trie[cur][nextchar - 'a'];
  }
  val[cur] = v;
}
