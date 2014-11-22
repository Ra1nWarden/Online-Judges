#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

bool primes[33333];
//int divisor[1000000001];
vector<int> primeNum;

int f(int x) {
  // if(divisor[x] != -1)
  //   return divisor[x];
  int result = 1;
  for(int i= 0; i < primeNum.size(); i++) {
    int p = primeNum[i];
    if(p > x)
      break;
    if(x % p == 0) {
      int count = 0;
      while(x % p == 0) {
	x /= p;
	count++;
      }
      result *= (count+1);
    }
  }
  if(x != 1)
    result *= 2;
  return result;
}

int main() {
  memset(primes, true, sizeof primes);
  primes[0] = false;
  primes[1] = false;
  for(int i = 2; i <= 33332; i++) {
    if(primes[i]) {
      //cout << i << endl;
      primeNum.push_back(i);
      for(int j = i+i; j <= 33332; j+=i)
	primes[j] = false;
    }
  }
  //memset(divisor, -1, sizeof divisor);
  //cout << "here" << endl;

  int tc;
  cin >> tc;
  while(tc--) {
    int a, b;
    cin >> a >> b;
    int result = 0;
    int maxIndex = -1;
    for(int i= a; i <= b; i++) {
      int next = f(i);
      if(next > result) {
	result = next;
	maxIndex = i;
      }
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, maxIndex, result);
  }

  return 0;
}
