#include <iostream>

using namespace std;

int MinimumRepresentation(string s) {
  int i = 0, j = 1, k = 0;
  int len = s.length();
  s += s;
  while(i < len && j < len) {
    k = 0;
    while(k < len && s[i+k] == s[j+k])
      k++;
    if(k >= len)
      break;
    if(s[i+k] > s[j+k])
      i = max(i+k+1, j+1);
    else
      j = max(i+1, j+k+1);
  }
  return min(i, j);
}

int main() {
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    cout << MinimumRepresentation(line) + 1 << endl;
  }
  return 0;
}
