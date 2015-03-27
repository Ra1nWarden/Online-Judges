#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  map<string, string> dict;
  for(int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    if(a.length() == b.length()) {
      dict[a] = a;
      dict[b] = b;
    } else {
      string val = a.length() < b.length() ? a : b;
      dict[a] = val;
      dict[b] = val;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i != 0)
      cout << " ";
    string word;
    cin >> word;
    cout << dict[word];
  }
  cout << endl;
  return 0;
}
