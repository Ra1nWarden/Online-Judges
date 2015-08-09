#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
#define MAXN 10

using namespace std;

vector<char> v;
map<char, int> m;
int n, ans;
bool adjMat[MAXN][MAXN];
vector<int> av;

void dfs(vector<int>& sofar, map<int, int>& pm, int sub_ans) {
  if(sofar.size() == n) {
    if(sub_ans < ans) {
      ans = sub_ans;
      av = sofar;
    }
    return;
  }
  for(int i = 0; i < n; i++) {
    if(pm.count(i) == 0) {
      int effect = 0;
      for(int j = 0; j < n; j++) {
	if(adjMat[i][j] && pm.count(j)) {
	  effect = max(effect, (int) sofar.size() - pm[j]);
	}
      }
      if(effect < ans) {
	pm[i] = sofar.size();
	sofar.push_back(i);
	dfs(sofar, pm, max(sub_ans, effect));
	sofar.pop_back();
	pm.erase(i);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  string line;
  while(getline(cin, line)) {
    av.clear();
    v.clear();
    m.clear();
    if(line[0] == '#')
      break;
    stringstream ss(line.c_str());
    string seg;
    vector<string> segs;
    set<char> chars;
    while(getline(ss, seg, ';')) {
      segs.push_back(seg);
      chars.insert(seg[0]);
      for(int i = 2; i < seg.length(); i++)
	chars.insert(seg[i]);
    }
    for(set<char>::iterator itr = chars.begin(); itr != chars.end(); itr++)
      v.push_back(*itr);
    n = v.size();
    for(int i = 0; i < v.size(); i++) {
      m[v[i]] = i;
    }
    memset(adjMat, false, sizeof adjMat);
    for(int i = 0; i < segs.size(); i++) {
      seg = segs[i];
      int u = m[seg[0]];
      for(int j = 2; j < seg.length(); j++) {
	int v = m[seg[j]];
	adjMat[u][v] = adjMat[v][u] = true;
      }
    }
    ans = 10;
    vector<int> vv;
    map<int, int> pm;
    dfs(vv, pm, 0);
    for(int i = 0; i < av.size(); i++) {
      cout << v[av[i]] << " ";
    }
    cout << "-> " << ans << endl;
  }
  return 0;
}
