#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool prime[1001];

int main() {
  memset(prime, true, sizeof prime);
  prime[0] = false;
  for(int i= 2; i <= 1000; i++) {
    if(prime[i]) {
      for(int j= i+i; j <= 1000; j+=i)
	prime[j] = false;
    }
  }
  int n, c;
  while(cin >> n >> c) {
    vector<int> print;
    for(int i= 1; i <= n; i++) {
      if(prime[i])
	print.push_back(i);
    }
    int printLength;
    if(print.size() % 2 == 1) {
      printLength = 2*c - 1;
    }
    else {
      printLength = 2 * c;
    }
    cout << n << " " << c << ":";
    if(printLength > print.size()) {
      for(int i= 0; i < print.size(); i++)
	cout << " " << print[i];
      cout << endl;
    } else {
      for(int i = (print.size() - printLength) / 2 ; i < print.size() - (print.size() - printLength) / 2; i++) {
	cout << " " << print[i];
      }
      cout << endl;
    }
    cout << endl;
    
  }
  return 0;
}
