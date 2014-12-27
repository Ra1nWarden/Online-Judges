#include <iostream>
#include <cstdio>

using namespace std;

long long Combi(long long a, long long b) {
  // special case when b > a
  //cout << "calling " << a << " " << b << endl;
  if(b > a) {
    return 0;
  }
  // Save some calculation by the fact 
  // a choose b = a choose (a - b)
  if(b > a / 2) {
    return Combi(a, a - b);
  }
  long long result = 1;
  for(long long i = 1; i <= b; i++) {
    result *= a--;
    result /= i;
  }
  return result;
}

int main() {
  long long n, m;
  while(cin >> n >> m && (n || m)) {
    printf("%lld things taken %lld at a time is %lld exactly.\n", n, m, Combi(n, m));
  }
  return 0;
}
