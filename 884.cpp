#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

long long countv[1000001];

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

int main() {
  memset(countv, 0, sizeof countv);
  vector<int> primes = GeneratePrime(sqrt(1000001));
  for(int i = 2; i <= 1000000; i++) {
    bool prime = true;
    for(int j = 0; j < primes.size(); j++) {
      int nextp = primes[j];
      if(i % nextp == 0) {
	prime = false;
	countv[i] = countv[i / nextp] + 1;
	break;
      }
    }
    if(prime)
      countv[i] = 1;
  }
  int n;
  vector<int> queries;
  while(cin >> n) {
    queries.push_back(n);
  }
  vector<int> sortedv = queries;
  long long result = 0;
  map<int, long long> resultm;
  sort(sortedv.begin(), sortedv.end());
  int runningi = 1;
  for(int i = 0; i < sortedv.size(); i++) {
    int thresh = sortedv[i];
    while(runningi <= thresh) {
      result += countv[runningi];
      runningi++;
      // cout << "number is : "; 
      // cout << runningi << endl;
    }
    resultm[thresh] = result;
  }
  for(int i = 0; i < queries.size(); i++)
    cout << resultm[queries[i]] << endl;
  return 0;
}
