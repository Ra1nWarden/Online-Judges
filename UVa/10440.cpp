#include <iostream>
#include <vector>

using namespace std;

bool DEBUG = false;

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int n, t, m;
    cin >> n >> t >> m;
    vector<int> arrivals;
    for(int j = 0; j < m; j++) {
      int time;
      cin >> time;
      arrivals.push_back(time);
    }
    int startIndex = m % n == 0 ? n : m % n;
    if(DEBUG)
      cout << "startIndex is " << startIndex << endl;
    int runningTime = arrivals[startIndex - 1];
    int tripCount = m % n == 0 ? m/n : m/n + 1;
    if(DEBUG)
      cout << "starting time is " << runningTime << endl;
    for(int j  = startIndex - 1 + n; j < m; j += n) {
      runningTime = runningTime + 2*t > arrivals[j] ? runningTime + 2*t : arrivals[j];
      if(DEBUG)
	cout << "runningTime for j " << j << " is " << runningTime << endl;
    }
    runningTime += t;
    cout << runningTime << " " << tripCount << endl;
  }
  return 0;
}
