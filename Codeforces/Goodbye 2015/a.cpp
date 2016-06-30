#include <iostream>
#include <sstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string line;
  getline(cin, line);
  stringstream ss(line.c_str());
  int n;
  ss >> n;
  string of, t;
  ss >> of >> t;
  if(t == "week") {
    cout << ((n == 5  || n == 6) ? 53 : 52) << endl;
  } else {
    int ans;
    switch(n) {
    case 31:
      ans = 7;
      break;
    case 30:
      ans = 11;
      break;
    default:
      ans = 12;
      break;
    }
    cout << ans << endl;
  }
  return 0;
}
