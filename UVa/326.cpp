#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long Factorial(long long a) {
  long long result = 1;
  for(int i= 1; i <= a; i++)
    result *= i;
  return result;
}

long long Perm(long long a, long long b) {
  long long result = 1;
  for(int i = 0; i < b; i++)
    result *= a--;
  return result;
}

long long Combi(long long a, long long b) {
  // special case when b > a
  if(b > a) {
    return 0;
  }
  // Save some calculation by the fact 
  // a choose b = a choose (a - b)
  if(b > a / 2) {
    return Combi(a, b - a);
  }
  long long result = 1;
  for(long long i = 1; i <= b; i++) {
    result *= a--;
    result /= i;
  }
  return result;
}

int main() {
  int n;
  while(cin >> n && n) {
    int diff[n][n];
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      diff[i][0] = x;
    }
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < n - i; j++) {
	diff[j][i] = diff[j+1][i-1] - diff[j][i-1];
      }
    }
    int k;
    cin >> k;
    long long result = 0;
    for(int i = 0; i < n; i++) {
      if(diff[0][i] != 0) {
	//cout << "i " << i << " " << diff[0][i] << " with k-1 " << k-1 << ": " << Combi(n + k-1, i) << endl;
	result += (diff[0][i] * Combi(n + k-1, i));
      }
    }
    printf("Term %d of the sequence is %lld\n", n + k, result);
  }
  return 0;
}
