#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, c;
  int cases = 1;
  while (cin >> n >> m >> c) {
    if (n == 0)
      break;
    vector<int> consumption;
    vector<bool> switches;
    for(int i = 0; i < n; i++) {
      int consume;
      cin >> consume;
      consumption.push_back(consume);
      switches.push_back(false);
    }
    int max = 0;
    int current = 0;
    for(int i = 0; i < m ; i++) {
      int device;
      cin >> device;
      if (!switches[device - 1]) {
	switches[device - 1] = true;
	current += consumption[device -1];
	if (current > max)
	  max = current;
      }
      else {
	switches[device -1] = false;
	current -= consumption[device -1];
      }
    }
    if (max > c) {
      cout << "Sequence " << cases << endl;
      cout << "Fuse was blown." << endl;
    }
    else {
      cout << "Sequence " << cases << endl;
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << max << " amperes." << endl;
    }
    cases++;
    cout << endl;
  }
  return 0;
}
