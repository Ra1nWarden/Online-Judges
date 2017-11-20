#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n >> ws;
    map<string, int> m;
    string line;
    while(n--) {
      getline(cin, line);
      if(m.count(line)) {
	m[line]++;
      } else {
	m[line] = 1;
      }
    }
    for(map<string, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
      cout << itr->first << " " << itr->second << endl;
    }
    if(tc)
      cout << endl;
  }
  return 0;
}
