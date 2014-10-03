#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, m;
  while(cin >> n >> m && (m || n)) {
    vector<int> nv, mv;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nv.push_back(x);
    }
    for(int i = 0; i < m; i++) {
      int x;
      cin >> x;
      mv.push_back(x);
    }
    if(m < n)
      cout << "Loowater is doomed!" << endl;
    else {
      sort(nv.begin(), nv.end());
      sort(mv.begin(), mv.end());
      int cost = 0;
      bool success = true;
      for(int i = nv.size() - 1; i >= 0; i--) {
	int next = nv[i];
	vector<int>::iterator itr = lower_bound(mv.begin(), mv.end(), next);
	if(itr == mv.end()) {
	  success = false;
	  break;
	}
	cost += *itr;
	mv.erase(itr);
      }
      if (!success)
	cout << "Loowater is doomed!" << endl;
      else
	cout << cost << endl;
    }
  }
  return 0;
}
