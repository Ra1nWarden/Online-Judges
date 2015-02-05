#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#define EPS 1e-8

using namespace std;

vector<int> GeneratePrime(int upper) {
  bool slots[upper];
  memset(slots, true, sizeof slots);
  vector<int> result;
  for(int i = 2; i < upper; i++) {
    if(slots[i]) {
      result.push_back(i);
      for(int j = i + i; j < upper; j += i) {
	slots[j] = false;
      }
    }
  }
  return result;
}

map<int, int> PrimeFactorize(int number) {
  vector<int> primes = GeneratePrime((int) sqrt(number) + 2);
  map<int, int> result;
  int numbercopy = number;
  for(int i = 0; i < primes.size(); i++) {
    int nextPrime = primes[i];
    if(numbercopy % nextPrime == 0) {
      int count = 0;
      while(numbercopy % nextPrime == 0) {
	count++;
	numbercopy /= nextPrime;
      }
      result[nextPrime] = count;
    }
  }
  if(numbercopy != 1) {
    result[numbercopy] = 1;
  }
  // special case for 1
  if(number == 1) {
    result[1] = 1;
  }
  return result;
}

int main() {
  int n, b;
  while(cin >> n >> b) {
    map<int, int> facts = PrimeFactorize(b);
    vector<int> primefact;
    map<int, int> actualfacts;
    for(map<int, int>::iterator itr = facts.begin(); itr != facts.end(); itr++) {
      primefact.push_back(itr->first);
      actualfacts[itr->first] = 0;
    }
    //cout << "one" << endl;
    double logsum = 0;
    for(int i = 2; i <= n; i++) {
      logsum += log10(i);
      for(int j = 0; j < primefact.size(); j++) {
	int curprime = primefact[j];
	int factcount = 0;
	int icopy = i;
	while(icopy % curprime == 0) {
	  icopy /= curprime;
	  factcount++;
	}
	actualfacts[curprime] = actualfacts[curprime] + factcount;
      }
    }
    //cout << "two" << endl;
    int zeros = 2e8;
    for(map<int, int>::iterator itr = facts.begin(); itr != facts.end(); itr++) {
      int nextn = actualfacts[itr->first] / itr->second;
      zeros = min(zeros, nextn);
    }
    //cout << "three" << endl;
    logsum /= log10(b);
    cout << zeros << " " << (int) floor(logsum + EPS) + 1 << endl;
  }
  return 0;
}
