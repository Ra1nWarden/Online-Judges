#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#define MAXN 120005

using namespace std;

string v[MAXN];
int idx;
set<string> s;

bool cmp(const string& a, const string& b) {
  if(a.length() != b.length()) {
    return a.length() < b.length();
  }
  return a < b;
}

int main() {
  ios::sync_with_stdio(false);
  idx = 0;
  string line;
  while(getline(cin, line)) {
    v[idx++] = line;
  }
  vector<string> ans;
  sort(v, v+idx, cmp);
  for(int i = 0; i < idx; i++) {
    string cur = v[i];
    for(int j = 1; j < cur.length(); j++) {
      string a = cur.substr(0, j);
      string b = cur.substr(j);
      if(s.count(a) && s.count(b)) {
	ans.push_back(cur);
	break;
      }
    }
    s.insert(cur);
  }
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
  return 0;
}
