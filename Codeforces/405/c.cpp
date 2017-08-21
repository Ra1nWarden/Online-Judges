#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 50;
string ans[maxn+5];
int n, k;
string each;

string generate(int i) {
  stringstream ss;
  ss << (char) ('A' + (i % 26));
  i /= 26;
  while(i) {
    ss << (char) ('a' + (i % 26));
    i /= 26;
  }
  return ss.str();
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> ws;
  int idx = 0;
  int seed = 0;
  for(int i = 0; i < k - 1; i++) {
    ans[idx++] = generate(seed++);
  }
  for(int i = 0; i < n - k + 1; i++) {
    cin >> each;
    if(each == "YES") {
      ans[idx] = generate(seed++);
    } else {
      ans[idx] = ans[idx - k + 1];
    }
    idx++;
  }
  for(int i = 0; i < n; i++) {
    if(i)
      cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
