#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string line;
  getline(cin, line);
  stringstream ss(line.c_str());
  int tc;
  ss >> tc;
  while(tc--) {
    getline(cin, line);
    getline(cin, line);
    int v[3] = {0, 0, 0};
    int num = 0;
    int vi = 0;
    for(int i = 0; i < line.length(); i++) {
      if(line[i] == ' ') {
	v[vi++] = num;
	num = 0;
	i += 2;
	continue;
      }
      if(num == -1)
	continue;
      if(isalpha(line[i])) {
	num = -1;
      } else {
	num = num * 10 + (line[i] - '0');
      }
    }
    v[2] = num;
    if(v[0] == -1) {
      v[0] = v[2] - v[1];
    } else if(v[1] == -1) {
      v[1] = v[2] - v[0];
    } else {
      v[2] = v[0] + v[1];
    }
    cout << v[0] << " + " << v[1] << " = " << v[2] << endl;
  }
  return 0;
}
