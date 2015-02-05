#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

bool prime[46343];
vector<int> primeNum;

int main() {
  memset(prime, true, sizeof prime);
  for(int i = 2; i <= 46342; i++) {
    if(prime[i]) {
      primeNum.push_back(i);
      for(int j = i+i; j <= 46341; j+=i) {
	prime[j] = false;
      }
    }
  }
  int tc = 1;
  long long n;
  while(cin >> n && n) {
    long long ncopy = n;
    long long result = 0;
    int factCount = 0;
    for(int i = 0; i < primeNum.size(); i++) {
      if(n % primeNum[i] == 0) {
	//cout << primeNum[i] << " divides " << ncopy << endl;
	int add = 1;
	factCount++;
	while(n % primeNum[i] == 0) {
	  n /= primeNum[i];
	  add *= primeNum[i];
	}
	result += add;
      }
    }
    if(factCount <= 1)
      result = ncopy + 1;
    else if(ncopy == 1)
      result = 2;
    printf("Case %d: %lld\n", tc++, result);
  }

  return 0;
}
