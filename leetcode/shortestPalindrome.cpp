#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == rev.back()) {
                int ii = i;
                int jj = rev.length() - 1;
                bool ok = true;
                while(ii > 0) {
                    if(s[ii] != rev[jj]) {
                        ok = false;
                        break;
                    }
		    ii--;
		    jj--;
                }
                if(ok) {
                    string ans = rev;
                    if(i < s.length() - 1) {
                        ans += s.substr(i + 1);
                    }
                    return ans;
                }
            }
        }
        return rev + s;
    }
};

int main() {
  Solution sol;
  cout << sol.shortestPalindrome("aacecaaa") << endl;
  return 0;
}
