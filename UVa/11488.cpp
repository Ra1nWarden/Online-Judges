#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxl = 200;
char str[maxl+5];

const int maxn = 10000010;
const int maxc = 2;

struct Trie {
  int ans;
  int trie[maxn][maxc];
  int val[maxn];
  int nextnode;
  Trie();
  void init();
  void insert(char* w);
};

Trie trie;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d\n", &n);
    trie.init();
    while(n--) {
      scanf("%s\n", str);
      trie.insert(str);
    }
    printf("%d\n", trie.ans);
  }
  return 0;
}

Trie::Trie() {}

void Trie::init() {
  ans = 0;
  nextnode = 1;
  memset(trie[0], 0, sizeof trie[0]);
  memset(val, 0, sizeof val);
}

void Trie::insert(char* w) {
  int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    int nextchar = w[i];
    if(trie[cur][nextchar - '0'] == 0) {
      memset(trie[nextnode], 0, sizeof trie[nextnode]);
      trie[cur][nextchar - '0'] = nextnode;
      val[nextnode] = 0;
      nextnode++;
    }
    cur = trie[cur][nextchar - '0'];
    val[cur]++;
    ans = max(ans, val[cur] * (i + 1));
  }
}
