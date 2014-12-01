#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool prime[31625];
vector<int> primeNum;

int main() {
  memset(prime, true, sizeof prime);
  for(int i = 2; i < 31625; i++) {
    if(prime[i]) {
      primeNum.push_back(i);
      for(int j = i+i; j < 31625; j+=i) {
	prime[j] = false;
      }
    }
  }
  
  int n;
  while(cin >> n && n) {
    int nc = n;
    vector<int> facts;
    for(int i= 0; i < primeNum.size(); i++) {
      if(nc % primeNum[i] == 0) {
	facts.push_back(primeNum[i]);
	while(nc % primeNum[i] == 0)
	  nc /= primeNum[i];
      }
    }
    if(nc != 1)
      facts.push_back(nc);
    
    int result = n;
    for(int i= 0; i < facts.size(); i++) {
      result = (result / facts[i]) * (facts[i] - 1);
    }
    cout << result << endl;
  }
  return 0;
}
