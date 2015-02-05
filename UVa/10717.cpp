#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
  return a * (b / gcd(a, b));
}

int lcm(const vector<int>& v) {
  if(v.size() == 2) {
    return lcm(v[0], v[1]);
  } else {
    int first = v[0];
    vector<int> remain(v.begin() + 1, v.end());
    int remainlcm = lcm(remain);
    return lcm(first, remainlcm);
  }
}

int main() {
  int m, n;
  while(cin >> m >> n && (m || n)) {
    vector<int> v;
    for(int i = 0; i < m; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    int result1[n];
    int result2[n];
    memset(result1, -1, sizeof result1);
    memset(result2, -1, sizeof result2);
    vector<int> q;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      q.push_back(x);
    }

    for(int i = 0; i < m; i++) {
      for(int j= i+1; j < m; j++) {
	for(int k = j + 1; k < m; k++) {
	  for(int l = k +1; l < m; l++) {
	    vector<int> selected;
	    selected.push_back(v[i]);
	    selected.push_back(v[j]);
	    selected.push_back(v[k]);
	    selected.push_back(v[l]);
	    int start = lcm(selected);
	    for(int each = 0; each < q.size(); each++) {
	      int query = q[each];
	      int r1 = query / start * start;
	      int r2 = r1 == query ? query : (query / start + 1) * start;
	      if(result1[each] == -1)
		result1[each] = r1;
	      else
		result1[each] = max(result1[each], r1);
	      if(result2[each] == -1)
		result2[each] = r2;
	      else
		result2[each] = min(result2[each], r2);
	    }
	  }
	}
      }
    }
    for(int i = 0; i < n; i++)
      cout << result1[i] << " " << result2[i] << endl;

  } 
  return 0;    
}
