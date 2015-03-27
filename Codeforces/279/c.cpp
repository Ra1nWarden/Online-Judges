#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  getline(cin, line);
  int a, b;
  cin >> a >> b;
  int av[line.length()];
  int bv[line.length()];
  int num = 0;
  for(int i = 0; i < line.length(); i++) {
    av[i] = ((num * 10) % a + (line[i] - '0')) % a;
    num = av[i];
  }
  num = 0;
  int mult = 1;
  for(int i = line.length() - 1; i >= 0; i--) {
    bv[i] = ((mult * (line[i] - '0')) % b + num) % b;
    mult = (mult * 10) % b;
    num = bv[i];
  }
  bool success = false;
  for(int i = 0; i < line.length() - 1; i++) {
    if(av[i] == 0 && bv[i+1] == 0 && line[i+1] != '0') {
      cout << "YES" << endl;
      cout << line.substr(0, i + 1) << endl;
      cout << line.substr(i+1) << endl;
      success = true;
      break;
    }
  }
  if(!success)
    cout << "NO" << endl;
  return 0;
}
