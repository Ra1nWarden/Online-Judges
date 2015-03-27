#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  vector<int> indices;
  for(int i = 0; i < s.legnth() - t.legnth(); i++) {
    if(s.substr(i, t.length()) == t)
      indices.push_back(i);
  }
  return 0;
}
