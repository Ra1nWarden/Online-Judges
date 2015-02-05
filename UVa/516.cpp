#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

bool prime[32768];
vector<int> primeNum;

typedef pair<int, int> com;

int main() {
  memset(prime, true, sizeof prime);
  for(int i = 2; i <= 32767; i++) {
    if(prime[i]) {
      primeNum.push_back(i);
      for(int j = i+i; j <= 32767; j+=i) {
	prime[j] = false;
      }
    }
  }

  string line;
  while(getline(cin, line)) {
    if(line == "0")
      break;
    long long num = 1;
    int b, p;
    stringstream ss(line.c_str());
    while(ss >> b >> p) {
      num *= pow(b, p);
    }
    num -= 1;
    vector<com> divisors;
    for(int i= 0; i < primeNum.size(); i++) {
      if(primeNum[i] > num)
	break;
      int nextPrime = primeNum[i];
      int count = 0;
      if(num % nextPrime == 0) {
	while(num % nextPrime == 0) {
	  count++;
	  num /= nextPrime;
	}
	divisors.push_back(make_pair(nextPrime, count));
      } 
    }

    for(vector<com>::reverse_iterator itr = divisors.rbegin(); itr != divisors.rend(); itr++) {
      if(itr != divisors.rbegin())
	cout << " ";
      cout << itr->first << " " << itr->second;
    }
    cout << endl;
  }
  

  return 0;
}
