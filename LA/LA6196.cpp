#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  string line;
  while(cin >> n && n) {
    getline(cin, line);
    vector<string> lines;
    for(int i= 0; i < n; i++) {
      getline(cin, line);
      lines.push_back(line);
    }
    sort(lines.begin(), lines.end());
    string less = lines[n/2 - 1];
    string more = lines[n/2];
    bool sub = true;
    string result = "";
    for(int i= 0; i < min(less.length(), more.length()); i++) {
      if(less[i] != more[i]) {
	sub = false;
	result += ((char) less[i] + 1);
	break;
      }
      else {
	result += less[i];
      }
    }
    cout << result << endl;
  }
  return 0;
}
