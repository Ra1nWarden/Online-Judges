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
  ll n;
  while(cin >> n && n) {
    ll c1, m1, c2, m2;
    cin >> c1 >> m1 >> c2 >> m2;
    ll d = GreatestCommonDivisor(m1, m2);
    if(n % d != 0) {
      cout << "failed" << endl;
    } else {
      pair<ll, ll> sol = SolveDiophantine(m1, m2, n);
      ll minCost = -1;
      ll minX, minY;
      
      bool second = (c1 * m2 / d) > (c2 * m1 / d);

      ll threshY = sol.second * d / m1;
      if(sol.second - (m1 / d) * threshY < 0)
	threshY -= 1;
      ll threshX = sol.first * d / (-m2);
      if(sol.first + (m2 / d) * threshX < 0)
	threshX += 1;

      // cout << sol.first + (m2 / d) * threshY << " " << sol.second - (m1 / d) * threshY << endl;
      // cout << sol.first + (m2 / d) * threshX << " " << sol.second - (m1 / d) * threshX << endl;
      // cout << second << endl;

      if(!second) {
	minX = sol.first + (m2 / d) * threshY;
	minY = sol.second - (m1 / d) * threshY;
      } else {
	minX = sol.first + (m2 / d) * threshX;
	minY = sol.second - (m1 / d) * threshX;
      }
 
      // for(ll i = 0; i > -1; i++) {
      // 	ll newX = sol.first + (m2 / d) * i;
      // 	ll newY = sol.second - (m1 / d) * i;
      // 	if(newY < 0)
      // 	  break;
      // 	if(newX < 0)
      // 	  continue;
      // 	else {
      // 	  ll newCost = newX * c1 + newY * c2;
      // 	  if(newCost < minCost || minCost == -1) {
      // 	    minCost = newCost;
      // 	    minX = newX;
      // 	    minY = newY;
      // 	  }
      // 	}
      // }
      
      // for(ll i = 0; i < 1; i--) {
      // 	ll newX = sol.first + (m2 / d) * i;
      // 	ll newY = sol.second - (m1 / d) * i;
      // 	if(newX < 0)
      // 	  break;
      // 	if(newY < 0)
      // 	  continue;
      // 	else {
      // 	  ll newCost = newX * c1 + newY * c2;
      // 	  if(newCost < minCost || minCost == -1) {
      // 	    minCost = newCost;
      // 	    minX = newX;
      // 	    minY = newY;
      // 	  }
      // 	}
      // }

      if(minX < 0 || minY < 0)
	cout << "failed" << endl;
      else {
	cout << minX << " " << minY << endl;
      }
      
    }
  }
  return 0;
}
