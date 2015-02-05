#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int sum, diff;
    cin >> sum >> diff;
    if ((sum + diff) % 2 != 0 || (sum - diff) % 2 != 0) {
      cout << "impossible" << endl;
      continue;
    }
    int big = (sum + diff) / 2;
    int small = (sum - diff) / 2;
    if (big < 0 || small < 0)
      cout << "impossible" << endl;
    else 
      cout << big << " " << small << endl;
  }
  return 0;
}
