#include <iostream>
#include <cstring>

using namespace std;

const int maxc = 26;
const int mod = 1e9+7;
int count[maxc+5];

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc >> ws;
  while(tc--) {
    string word;
    getline(cin, word);
    int len = word.length();
    memset(count, 0, sizeof count);
    int curr = 1;
    for(int i = 0; i < len; i++) {
      int c = word[i] - 'A';
      int prev = curr;
      curr = (((curr * 2LL) % mod) + mod - count[c]) % mod;
      count[c] = prev;
    }
    cout << curr << endl;
  }
  return 0;
}
