#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool prime[10001];

int main() {
  memset(prime, true, sizeof prime);
  prime[0] = prime[1] = false;
  vector<int> primeNum;
  for(int i= 2; i < 10001; i++) {
    if(prime[i]) {
      primeNum.push_back(i);
      for(int j= i+i; j < 10001; j+=i)
	prime[j] = false;
    }
  }
  int num;
  while(cin >> num) {
    int cap = num / 3;
    int result = 0;
    for(int i= 0; i < primeNum.size(); i++) {
      int onePrime = primeNum[i];
      if(onePrime > cap)
	break;
      for(int j= i; j < primeNum.size(); j++) {
	int twoPrime = primeNum[j];
	int remain = num - onePrime - twoPrime;
	if(remain < twoPrime)
	  break;
	if(prime[remain])
	  result++;
      }
    }
    cout << result << endl;
  }
  return 0;
}
