#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

map<ll, vector<ll> > remainderMap;
map<ll, map<ll, ll> > factorMap;
vector<ll> primes;
static const ll r = 1000000007;
static const ll n = 3165;

map<ll, ll> primeFactorize(ll number) {
  if(factorMap.count(number))
    return factorMap[number];
  map<ll, ll> result;
  ll numbercopy = number;
  for(ll i = 0; i < primes.size(); i++) {
    ll nextprime = primes[i];
    if(numbercopy % nextprime == 0) {
      ll count = 0;
      while(numbercopy % nextprime == 0) {
	count++;
	numbercopy /= nextprime;
      }
      result[nextprime] = count;
    }
  }
  if(numbercopy != 1) {
    result[numbercopy] = 1;
  }
  if(number == 1) {
    result[1] = 1;
  }
  return factorMap[number] = result;
}

vector<ll> findRemainder(ll number) {
  if(remainderMap.count(number))
    return remainderMap[number];
  vector<ll> result;
  result.push_back(number % r);
  ll next = number;
  while(true) {
    next = next * number % r;
    if(next == result[0] || result.size() == 10000000 - number + 1)
      break;
    result.push_back(next);
  }
  return remainderMap[number] = result;
}

int main() {
  bool slots[n];
  memset(slots, true, sizeof slots);
  for(int i = 2; i < n; i++) {
    if(slots[i]) {
      primes.push_back(i);
      for(int j = i+i; j < n; j += i) {
	slots[j] = false;
      }
    }
  }
  
  ll x;
  while(cin >> x) {
    ll result = 1;
    for(ll i = 1; i <= x; i++) {
      //cout << "loop " << i << endl;
      map<ll, ll> primeFactors = primeFactorize(i);
      //cout << "finished factorize "  << i << endl;
      for(map<ll, ll>::iterator itr = primeFactors.begin(); itr != primeFactors.end(); itr++) {
	ll base = itr->first;
	ll power = itr->second * (x - i + 1);
	//cout << base << " " << power << endl;
	vector<ll> remainder = findRemainder(base);
	//cout << "found reaminder " << base << endl;
	result *= remainder[power % remainder.size() - 1 + remainder.size()];
	result %= r;
	//cout << "result is now " << result << endl;
      }
      //cout << "finished " << i << endl;
    }
    cout << result << endl;

  }


  return 0;
}
