#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int period;
    cin >> period;
    vector<bool> checks(period);
    for(int i = 0; i < period; i++)
      checks[i] = false;
    int sizes;
    cin >> sizes;
    for(int i = 0; i < sizes; i++) {
      int current;
      cin >> current;
      for(int j = current; j <= period; j += current) 
	checks[j-1] = true;
    }
    int result = 0;
    for(int i = 0; i < period; i++) {
      if(i % 7 == 5 || i % 7 == 6)
	continue;
      if(checks[i])
	result++;
    }
    cout << result << endl;
  }
  return 0;
}
