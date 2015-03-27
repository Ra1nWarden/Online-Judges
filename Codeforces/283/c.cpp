#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> v;
  string line;
  getline(cin, line);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    v.push_back(line);
  }
  int remove = 0;
  bool flag[n-1];
  memset(flag, false, sizeof flag);
  for(int i = 0; i < m; i++) {
    //cout << "index " << i << endl;
    bool flagcopy[n-1];
    memcpy(flagcopy, flag, sizeof flag);
    char prev = ' ';
    for(int j = 0; j < n; j++) {
      if(j == 0) {
	prev = v[j][i];
	continue;
      }
      if(v[j][i] > prev && !flag[j-1]) {
	flag[j-1] = true;
      }
      //cout << "comparing " << v[j][i] << " with " << prev << endl;
      if(v[j][i] < prev && !flag[j-1]) {
	remove++;
	//cout << v[j][i] << " less than " << prev << " at " << j << " " << i << endl;
	memcpy(flag, flagcopy, sizeof flag);
	break;
      }
      prev = v[j][i];
    }
  }
  cout << remove << endl;
  return 0;
}
