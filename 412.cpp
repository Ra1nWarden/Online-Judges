#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int n;
  vector<int> v;
  while(cin >> n && n) {
    v.clear();
    for(int i= 0; i < n; i++) {
      int x;
      cin >>x;
      v.push_back(x);
    }
    double total = n * (n-1) / 2;
    double coprime = 0;
    for(int i = 0; i < n; i++) {
      for(int j= i+1; j < n; j++) {
	if(gcd(v[i], v[j]) == 1)
	  coprime++;
      }
    }
    if(coprime == 0)
      cout << "No estimate for this data set." << endl;
    else
      printf("%.6f\n", sqrt(6 / (coprime / total)));
  }
  return 0;
}
