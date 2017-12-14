#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n >> ws;
    vector<string> v;
    string line;
    while(n--) {
      getline(cin, line);
      v.push_back(line);
    }
    sort(v.begin(), v.end());
    bool ans = false;
    for(int i = 0; i < v.size() - 1; i++) {
      if(v[i].length() > v[i+1].length())
	continue;
      bool ok = true;
      for(int j = 0; j < v[i].length(); j++) {
	if(v[i][j] != v[i+1][j]) {
	  ok = false;
	  break;
	}
      }
      if(ok) {
	ans = true;
	break;
      }
    }
    cout << (ans ? "NO" : "YES") << endl;
  }
  return 0;
}
