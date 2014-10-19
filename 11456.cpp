#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findLIS(vector<int> v) {
  vector<int> lis;
  for(int i= 0; i < v.size(); i++) {
    int start = v[i];
    vector<int> lisV;
    lisV.push_back(start);
    for(int j= i+1; j < v.size(); j++) {
      int next = v[j];
      vector<int>::iterator itr = lower_bound(lisV.begin(), lisV.end(), next);
      if(itr == lisV.end()) {
	lisV.push_back(next);
      } else if (itr == lisV.begin()) {
	continue;
      } else {
	*itr = next;
      }
    }
    lis.push_back(lisV.size());
  }
  return lis;
}

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int n;
    cin >> n;
    vector<int> v;
    vector<int> rev;
    for(int j = 0; j < n; j++) {
      int x;
      cin >> x;
      v.push_back(x);
      rev.push_back(-x);
    }
    vector<int> lis = findLIS(v);
    vector<int> lds = findLIS(rev);
    int result = 0;
    for(int j = 0; j < n; j++) {
      result = max(result, lis[j] + lds[j] - 1);
    }
    cout << result << endl;
  }
  return 0;
}
