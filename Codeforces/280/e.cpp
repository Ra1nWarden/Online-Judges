#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;

int counter[1000000];

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a * (b / gcd(a, b));
}

pair<ll, ll> ExtendedEuclid(ll a, ll b) {
  if (b == 0) {
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
  memset(counter, 0, sizeof counter);
  ll n, m, dx, dy;
  cin >> n >> m >> dx >> dy;
  ll result = -1;
  ll max = -1;
  for(ll i= 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    // if(x == 0) {
    //   counter[y]++;
    //   if(counter[y] > max) {
    // 	max = counter[y];
    // 	result = y;
    //   }
    //   cout << y << " speical and " << n << endl;
    //   continue;
    // }
    ll d = gcd(dx, n);
    pair<ll, ll> sol = SolveDiophantine(dx, n, x);
    //cout << dx << "x + " << n << "y = " << x << endl;
    //cout << "solution: " << sol.first << " and " << sol.second << endl;
    ll ysol = sol.second - (dx / d) * (sol.second * d / dx + 1);
    if(ysol > 0)
      ysol -= (dx / d);
    ll k = (- ysol * n + x) / dx;
    ll totaly = k * dy;
    ll diff = ((totaly - y) / n + 1) * n + y - totaly;
    diff %= n;
    //cout << "k is " << k << endl;
    //cout << diff << " and " << n << endl;
    counter[diff]++;
    if(counter[diff] > max) {
      max = counter[diff];
      result = diff;
    }
  }
  cout << 0 << " " << result << endl;
  return 0;
}
