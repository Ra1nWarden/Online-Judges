#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#define MAXN 205

using namespace std;

int n;
string name;
map<string, int> m;
int next;
vector<int> sons[MAXN];
int dp[MAXN][2];
int unique[MAXN][2];

int f(int root, int used) {
  if(dp[root][used] != -1)
    return dp[root][used];
  if(used == 0) {
    int ans = 0;
    bool flag = true;
    for(int i = 0; i < sons[root].size(); i++) {
      if(f(sons[root][i], 0) == f(sons[root][i], 1)) {
	flag = false;
	ans += dp[sons[root][i]][0];
      } else if(f(sons[root][i], 0) > f(sons[root][i], 1)) {
	flag = flag && unique[sons[root][i]][0];
	ans += dp[sons[root][i]][0];
      } else {
	flag = flag && unique[sons[root][i]][1];
	ans += dp[sons[root][i]][1];
      }
    }
    unique[root][used] = (flag ? 1 : 0);
    //cout << "dp " << root << ", " << used << ": " << ans << endl;
    return dp[root][used] = ans;
  } else {
    int ans = 1;
    bool flag = true;
    for(int i = 0; i < sons[root].size(); i++) {
      ans += f(sons[root][i], 0);
      flag = flag && unique[sons[root][i]][0];
    }
    unique[root][used] = (flag ? 1 : 0);
    //cout << "dp " << root << ", " << used << ": " << ans << endl;
    return dp[root][used] = ans;
  }
}

int main() {
  while(cin >> n && n) {
    m.clear();
    next = 0;
    for(int i = 0; i < n; i++)
      sons[i].clear();
    getline(cin, name);
    getline(cin, name);
    m[name] = next++;
    for(int i = 0; i < n - 1; i++) {
      getline(cin, name);
      stringstream ss(name.c_str());
      string a, b;
      ss >> a >> b;
      if(m.count(a) == 0)
	m[a] = next++;
      if(m.count(b) == 0)
	m[b] = next++;
      sons[m[b]].push_back(m[a]);
    }
    memset(dp, -1, sizeof dp);
    memset(unique, -1, sizeof unique);
    if(f(0, 0) == f(0, 1)) {
      cout << f(0, 0) << " No" << endl;
    } else if(f(0,0) > f(0, 1)) {
      cout << f(0, 0) << " " << (unique[0][0] ? "Yes" : "No") << endl;
    } else {
      cout << f(0, 1) << " " << (unique[0][1] ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
