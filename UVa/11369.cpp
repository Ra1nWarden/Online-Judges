#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DEBUG = false;

int main() {
  int n;
  cin >> n;
  for(int i =0; i < n; i++) {
    int count;
    cin >> count;
    vector<int> prices;
    for(int j= 0; j < count; j++) {
      int x;
      cin >> x;
      prices.push_back(x);
    }
    sort(prices.begin(), prices.end());
    int result = 0;
    int startIndex = count % 3;
    if(DEBUG)
      cout << "startIndex is " << startIndex << endl;
    for(int j = startIndex; j < count; j += 3) {
      if(DEBUG) {
	cout << "j is " << j << endl;
	cout << "prices[j] is " << prices[j] << endl;
      }
      result += prices[j];
    }
    cout << result << endl;
  }
  return 0;
}
