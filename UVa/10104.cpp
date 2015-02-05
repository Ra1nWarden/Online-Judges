#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;

ll GreatestCommonDivisor(ll a, ll b) {
  return b == 0 ? a : GreatestCommonDivisor(b, a % b);
}

pair<ll, ll> ExtendedEuclid(ll a, ll b) {
  if(b == 0) {
    return make_pair(1, 0);
  }
  pair<ll, ll> prev = ExtendedEuclid(b, a % b);
  ll x1 = prev.second;
  ll y1 = prev.first - (a / b) * prev.second;
  return make_pair(x1, y1);
}

pair<ll, ll> SolveDiophantine(ll a, ll b, ll c) {
  pair<ll, ll> sol = ExtendedEuclid(a, b);
  ll result = sol.first * a + sol.second * b;
  return make_pair(sol.first * c / result, sol.second * c / result);
}

int main() {
  ll a, b;
  while(cin >> a >> b) {
    ll d = GreatestCommonDivisor(a, b);
    pair<ll, ll> sol = SolveDiophantine(a, b, d);
    cout << sol.first << " " << sol.second << " " << d << endl;
  }
  return 0;
}
