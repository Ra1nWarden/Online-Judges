#include <iostream>
#include <cstdlib>

using namespace std;

struct Character {
  char ch;
  long long len;
  Character() {}
};

const int maxl = 200000;

Character s[maxl+5];
Character t[maxl+5];
int f[maxl+5];
int sl, tl;
int n, m;

void read(Character* v, int& vi, int nodes) {
  string node;
  for(int i = 0; i < nodes; i++) {
    cin >> node;
    int cut;
    for(cut = 0; cut < node.length(); cut++) {
      if(node[cut] == '-')
	break;
    }
    char c = node[cut+1];
    int cnt = atoi(node.substr(0, cut).c_str());
    if(vi > 0 && v[vi-1].ch == c) {
      v[vi-1].len += cnt;
    } else {
      v[vi].ch = c;
      v[vi].len = (long long) cnt;
      vi++;
    }
  }
  cin >> ws;
}

bool ok(const Character& a, const Character& b) {
  return a.ch == b.ch && a.len == b.len;
}

bool more(const Character& a, const Character& b) {
  if(a.ch != b.ch)
    return false;
  return a.len >= b.len;
}

void kmp_init() {
  f[0] = f[1] = 0;
  for(int i = 1; i < tl - 2; i++) {
    int j = f[i];
    while(j && !ok(t[i+1], t[j+1])) {
      j = f[j];
    }
    f[i+1] = ok(t[i+1], t[j+1]) ? j + 1 : 0;
  }
}

int kmp_match() {
  kmp_init();
  int ans = 0;
  int j = 0;
  for(int i = 0; i < sl; i++) {
    while(j && !ok(s[i], t[j+1]))
      j = f[j];
    if(ok(s[i], t[j+1]))
      j++;
    if(j == tl - 2) {
      int bstart = i - tl + 2;
      int aend = i + 1;
      if(bstart > -1 && bstart < sl && more(s[bstart], t[0]) && aend < sl && more(s[aend], t[tl-1]))
	ans++;
      j = f[j];
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  sl = tl = 0;
  cin >> n >> m >> ws;
  read(s, sl, n);
  read(t, tl, m);
  if(tl == 1) {
    long long ans = 0;
    for(int i = 0; i < sl; i++) {
      if(more(s[i], t[0])) {
	ans += s[i].len - t[0].len + 1;
      }
    }
    cout << ans << endl;
  } else if(tl == 2) {
    int ans = 0;
    for(int i = 0; i < sl - 1; i++) {
      if(more(s[i], t[0]) && more(s[i+1], t[1])) {
	ans++;
      }
    }
    cout << ans << endl;
  } else {
    cout << kmp_match() << endl;
  }
  return 0;
}
