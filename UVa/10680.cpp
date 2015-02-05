#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

bool prime[1000001];
int resultv[1000001];
vector<int> primeNum;
map<int, vector<int> > lastDigit;

int main() {
  memset(resultv, -1, sizeof resultv);
  memset(prime, true, sizeof prime);
  prime[0] = false;
  for(int i = 2; i <= 1000000; i++) {
    if(prime[i]) {
      primeNum.push_back(i);
      for(int j= i+i; j <= 1000000; j+=i) {
	prime[j] = false;
      }
    }
  }
  for(int i = 1; i <= 9; i++) {
    vector<int> remainder;
    int next = i;
    do {
      //cout << "for " << i << " pushing " << next << endl;
      remainder.push_back(next);
      next *= i;
      next %= 10;
    } while(remainder[0] != next);
    lastDigit[i] = remainder;
  }
  

  int n;
  while(cin >> n && n) {
    if(resultv[n] != -1) {
      cout << resultv[n] << endl;
      continue;
    }
    int pow5 = log10(n) / log10(5);
    int pow2 = log10(n) / log10(2);
    //cout << n << ": " << pow5 << ", " << pow2 << endl;
    int result = 1;
    for(int i= 0; i < primeNum.size(); i++) {
      //cout << primeNum[i] << endl;
      if(primeNum[i] > n)
	break;
      if(primeNum[i] == 5)
	continue;
      else if(primeNum[i] == 2) {
	int power = pow2 - pow5;
	if(power == 1)
	  power = 0;
	else {
	  power = (power - 1) % lastDigit[2].size();
	  if(power < 0)
	    power += lastDigit[2].size();
	}
	result *= lastDigit[2][power];
	//result *= pow(2, pow2 - pow5);
	//cout << primeNum[i] << "->: " << result  << endl;
      } else {
	//cout << "else branch" << endl;
	//cout << primeNum[i] << " pow " << log10(n) / log10(primeNum[i]) << endl;
	//cout << pow(primeNum[i], log10(n) / log10(primeNum[i])) << endl;
	int power = (int)(log10(n)/log10(primeNum[i]));
	//cout << "first power is " << power << endl;
	if(power == 1)
	  power = 0;
	else {
	  //cout << "this else branch" << endl;
	  //cout << (power - 1) << " and " << lastDigit[primeNum[i] % 10].size();
	  power = (power - 1) % lastDigit[primeNum[i] % 10].size();
	  if(power < 0)
	    power += lastDigit[primeNum[i] % 10].size();
	}
	//cout << "power is " << power << endl;
	result *= lastDigit[primeNum[i]%10][power];

	//result *= pow(primeNum[i] % 10, (int) (log10(n) / log10(primeNum[i])));
	//cout << primeNum[i] << "->: " << result << endl;
      }
      //cout << "result is " << result << endl;
      result %= 10;
    }
    resultv[n] = result;
    cout << result << endl;
  }
  return 0;
}
