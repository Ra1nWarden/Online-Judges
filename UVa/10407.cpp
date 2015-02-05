#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int gcd(const vector<int>& v) {
  if(v.size() == 1)
    return v[0];
  if(v.size() == 2) {
    return gcd(v[0], v[1]);
  } else {
    int first = v[0];
    vector<int> remain(v.begin()+1, v.end());
    int remainGCD = gcd(remain);
    return gcd(first, remainGCD);
  }
}

int main() {
  while(true) {
    vector<int> v;
    int prev = 0;
    bool firstEntry = true;
    while(true) {
      int x;
      cin >> x;
      if(x == 0)
	break;
      if(!firstEntry) {
	//cout << "pushing " << x - prev << endl;
	v.push_back(abs(x - prev));
      }
      firstEntry = false;
      prev = x;
    }
    if(v.empty())
      break;
    cout << gcd(v) << endl;
  }

  return 0;
}
