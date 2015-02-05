#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll n, m;
  while(cin >> n >> m) {
    ll mod = (1 << m);
    vector<ll> v;
    v.push_back(0);
    v.push_back(1);
    if(m == 0) {
      cout << (v[0] % mod) << endl;
    } else {
      for(ll i = 2; i <= n; i++) {
	ll sum = (v[v.size() - 2] + v[v.size() - 1]) % mod;
	//cout << sum << endl;
	if(sum == v[0] && (v.back() + sum) % mod == v[1])
	  break;
	v.push_back(sum);
      }
      // cout << "v elements" << endl;
      // for(int i = 0; i < v.size(); i++)
      // 	cout << v[i] << " ";
      // cout << endl;
      // cout << "v size is " << v.size() << endl;
      
      cout << v[n % v.size()] << endl;
    }
  }
  return 0;
}
