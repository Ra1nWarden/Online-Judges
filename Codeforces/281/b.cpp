#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool tie = false;

bool operator<(const vector<ll>& one, const vector<ll>& two) {
  ll sum1 = 0;
  ll sum2 = 0;
  for(ll i= 0; i < one.size(); i++)
    sum1 += one[i];
  for(ll i= 0; i < two.size(); i++)
    sum2 += two[i];
  if(sum1 == sum2) {
    for(ll i = 0; i < one.size(); i++) {
      if(i > two.size() - 1) {
	return false;
      }
      if(one[i] != two[i])
	return one[i] < two[i];
    }
    tie = true;
    return false;
  } else
    return sum1 < sum2;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> first;
  vector<ll> second;
  ll last = 0;
  for(ll i = 0; i < n; i++) {
    ll num;
    cin >> num;
    if(num > 0)
      first.push_back(num);
    else
      second.push_back(-num);
    if(i == n-1)
      last = num;
  }
  bool result = first < second;
  if(tie) {
    cout << (last > 0 ? "first" : "second") << endl;
  } else {
    cout << (result ? "second" : "first") << endl;
  }
  return 0;
}
