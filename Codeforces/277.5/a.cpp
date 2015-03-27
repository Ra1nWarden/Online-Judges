#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> swapa;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
  }
  vector<int> sorted = arr;
  sort(sorted.begin(), sorted.end());
  vector<swapa> results;
  for(int i= 0; i < arr.size(); i++) {
    int orig = arr[i];
    int dest = sorted[i];
    if(orig != dest) {
      vector<int>::iterator itr = find(arr.begin() + i, arr.end(), dest);
      int index = itr - arr.begin();
      *itr = orig;
      arr[i] = dest;
      results.push_back(make_pair(i, index));
    }
  }

  cout << results.size() << endl;
  for(int i= 0; i < results.size(); i++) {
    swapa print = results[i];
    cout << print.first << " " << print.second << endl;
  }
  return 0;
}
