#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool has_next(string& str) {
  for(int i = str.length() - 1; i > -1; i--) {
    if(str[i] != 'Z') {
      str[i]++;
      return true;
    } else {
      str[i] = 'A';
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n >> ws && n) {
    vector<string> v;
    string word;
    while(n--) {
      cin >> word;
      v.push_back(word);
    }
    sort(v.begin(), v.end());
    string a = v[v.size() / 2 - 1];
    string b = v[v.size() / 2];
    string ans;
    for(int len = 1; len <= a.length(); len++) {
      ans = a.substr(0, len);
      bool found = false;
      do {
	if(ans >= a && ans < b) {
	  found = true;
	  break;
	} if(ans >= b) {
	  break;
	}
      } while(has_next(ans));
      if(found)
	break;
    }
    cout << ans << endl;
  }
  return 0;
}
