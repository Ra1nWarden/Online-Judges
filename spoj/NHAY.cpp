#include <iostream>
#include <string>
#include <vector>

using namespace std;

string pattern, str;

int main() {
  ios::sync_with_stdio(false);
  while(getline(cin, pattern)) {
    getline(cin, pattern);
    getline(cin, str);
    // if(pattern.length() > str.length()) {
    //   cout << endl;
    //   continue;
    // }
    vector<int> f(pattern.length() + 5, 0);
    f[0] = f[1] = 0;
    for(int i = 1; i < pattern.length(); i++) {
      int j = f[i];
      while(j && pattern[i] != pattern[j])
	j = f[j];
      f[i+1] = pattern[i] == pattern[j] ? j + 1 : 0;
    }
    int j = 0;
    vector<int> ans;
    for(int i = 0; i < str.length(); i++) {
      while(j && str[i] != pattern[j])
	j= f[j];
      if(str[i] == pattern[j])
	j++;
      if(j == pattern.length()) {
	ans.push_back(i - pattern.length() + 1);
	j = f[j];
      }
    }
    if(ans.empty()) {
      cout << endl;
    } else {
      for(int i = 0; i < ans.size(); i++) {
	cout << ans[i] << endl;
      }
    }
  }
  return 0;
}
