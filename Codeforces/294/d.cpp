#include <iostream>
#include <map>

using namespace std;

int v[26];
map<long long, int> m[26];

int main() {
  for(int i =0; i < 26; i++)
    cin >> v[i];
  string line;
  getline(cin, line);
  getline(cin, line);
  long long prefixsum = 0;
  long long res = 0;
  for(int i = 0; i < line.length(); i++) {
    prefixsum += v[line[i] - 'a'];
    if(m[line[i] - 'a'].count(prefixsum - v[line[i] - 'a'])) {
      res += m[line[i] - 'a'][prefixsum - v[line[i] - 'a']];
    }
    if(m[line[i] - 'a'].count(prefixsum))
      m[line[i] - 'a'][prefixsum] = m[line[i] - 'a'][prefixsum]+1;
    else
      m[line[i] - 'a'][prefixsum] = 1;
  }
  cout << res << endl;
  return 0;
}
