#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DEBUG = false;

int main() {
  int n;
  while(cin >> n) {
    vector<int> v;
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    vector<int> forward(v.size(), 1);
    vector<int> backward(v.size(), 1);
    vector<int> f;
    vector<int> b;
    for(int i = 0; i < n; i++) {
      if(f.empty()) {
	f.push_back(v[i]);
      }
      else if(v[i] < f[0]) {
	f[0] = v[i];
      }
      else if(v[i] > f.back()) {
	f.push_back(v[i]);
      }
      else {
	vector<int>::iterator itr = lower_bound(f.begin(), f.end(), v[i]);
	*itr = v[i];
      }
      forward[i] = f.size();
    }
    for(int i = n-1; i >= 0; i--) {
      if(b.empty()) {
	b.push_back(v[i]);
      }
      else if(v[i] < b[0]) {
	b[0] = v[i];
      }
      else if(v[i] > b.back()) {
	b.push_back(v[i]);
      }
      else {
	vector<int>::iterator itr = lower_bound(b.begin(), b.end(), v[i]);
	*itr = v[i];
      }
      backward[i] = b.size();
    }
    int result = 1;
    for(int i= 0; i < n; i++) {
      if(DEBUG)
	cout << "index at " << i << " which is " << v[i] << " forward " << forward[i] << " backward " << backward[i] << endl;
      int y = min(forward[i], backward[i]) * 2 - 1;
      if(y > result)
	result = y;
    }
    cout << result << endl;
  }
  return 0;
}
