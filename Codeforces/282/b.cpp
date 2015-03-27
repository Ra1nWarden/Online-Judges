#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>

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

int CountFactors(int number) {
  map<int, int> facts = PrimeFactorize(number);
  int result = 1;
  for(map<int, int>::iterator itr = facts.begin(); itr != facts.end(); itr++) {
    if(itr->first != 1) {
      result *= (itr->second + 1);
    }
  }
  return result;
}


int main() {
  int a, b;
  cin >> a >> b;
  int mult = a - b;
  if(mult == 0)
    cout << "infinity" << endl;
  else {
    if(b < mult / 2) {
      int result = CountFactors(mult);
      //cout << "result here is " << result << endl;
      for(int i = 1; i <= b; i++) {
	if(mult % i == 0)
	  result--;
      }
      cout << result << endl; 
    } else {
      int result = 0;
      for(int i = b+1; i <= mult; i++) {
	if(mult % i == 0)
	  result++;
      }
      cout << result << endl;
    }
  }
  return 0;
}
