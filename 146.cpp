#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string line;
  while(true) {
    getline(cin, line);
    if (line == "#")
      break;
    bool success = next_permutation(line.begin(), line.end());
    if(success)
      cout << line << endl;
    else
      cout << "No Successor" << endl;
  }
  return 0;
}
