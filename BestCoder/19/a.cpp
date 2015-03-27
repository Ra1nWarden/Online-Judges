#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool prime[31701];
vector<int> primeNum;

int main() {
  memset(prime, true, sizeof prime);
  //primeNum.push_back(1);
  for(int i= 2; i <= 31700; i++) {
    if(prime[i]) {
      primeNum.push_back(i);
      for(int j= i+i; j <= 31700; j+=i) {
	prime[j] = false;
      }
    }
  }
  
  int n;
  while(cin >> n) {
    //cout << "read " << n << endl;
    if(n == 1) {
      cout << 0 << endl;
      continue;
    }
    int ncopy = n;
    
    int result;
    for(int i= 0; i < primeNum.size(); i++) {
      int nextPrime = primeNum[i];
      //cout << nextPrime << " -> " << n << endl;
      if(nextPrime > n)
	break;
      if(n % nextPrime == 0)
      result = nextPrime;
      while(n % nextPrime == 0) {
	n /= nextPrime;
      }
    }
    //cout << result << ", " << n << endl;
    
    cout << (result > n ? ncopy/result : ncopy/n) << endl;
  }

  return 0;
}
