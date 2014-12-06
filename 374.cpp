#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll b, p, m;
  while(cin >> b >> p >> m) {
    vector<ll> v;
    ll r = 1;
    if(p == 0)
      v.push_back(1 % m);
    for(ll i = 0; i < p; i++) {
      r *= (b % m);
      r %= m;
      if(!v.empty() && v[0] == r) {
	break;
      }
      v.push_back(r);
    }
    cout << v[(p - 1 + v.size()) % v.size()] << endl;
  }
  return 0;
}
