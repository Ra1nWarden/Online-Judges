#include <iostream>
#include <sstream>

using namespace std;

int main() {
  string line;
  while(getline(cin, line)) {
    istringstream iss(line.c_str());
    string a, b;
    iss >> a >> b;
    int ai = 0; int bi = 0;
    bool success = true;
    while(ai != a.length()) {
      char match = a[ai];
      bool found = false;
      while(bi != b.length()) {
	char test = b[bi];
	if (match == test) {
	  found = true;
	  bi++;
	  break;
	} else {
	  bi++;
	}
      }
      if (found) {
	ai++;
      } else {
	success = false;
	break;
      }
    }
    cout << (success ? "Yes" : "No") << endl;
  }
  return 0;
}
