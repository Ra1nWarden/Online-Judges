#include <iostream>
#include <algorithm>
#include <cstdio>

int fib[41];

using namespace std;

int main() {
  fib[0] = 1;
  fib[1] = 2;
  for(int i = 2; i < 41; i++)
    fib[i] = fib[i-1] + fib[i-2];
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int xc = x;
    string result(41, '0');
    int last = -1;
    while(xc != 0) {
      int* bound = lower_bound(fib, fib + 41, xc);
      if(*bound > xc)
	bound--;
      if(last == -1)
	last = bound - fib;
      xc -= *bound;
      result[bound - fib] = '1';
    }

    result = result.substr(0, last + 1);
    reverse(result.begin(), result.end());

    printf("%d = %s (fib)\n", x, result.c_str());

  }
  return 0;
}
