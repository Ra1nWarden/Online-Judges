#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  map<string, int> m;
  int ans = 1;
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    if(m.count(line)) {
      m[line] = m[line] + 1;
    } else {
      m[line] = 1;
    }
    ans = max(ans, m[line]);
  }
  cout << ans << endl;
  return 0;
}
