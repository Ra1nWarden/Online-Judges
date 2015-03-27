#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 500005

using namespace std;


int prefix_sum[MAXN];
int n;
long long sp[MAXN];

int main() {
  string line;
  getline(cin, line);
  memset(prefix_sum, 0, sizeof prefix_sum);
  n = line.length();
  for(int i = 0; i < n; i++) {
    if(line[i] == 'I' || line[i] == 'E' || line[i] == 'A'|| line[i] == 'O'|| line[i] == 'U'|| line[i] == 'Y') {
      if(i == 0)
	prefix_sum[i] = 1;
      else
	prefix_sum[i] = prefix_sum[i-1] + 1;
    } else {
      if(i > 0)
	prefix_sum[i] = prefix_sum[i-1];
    }
  }
  double res = 0;
  sp[1] = prefix_sum[n-1];
  res += sp[1] / 1.0;
  //printf("res is %f\n", res);
  for(int i = 2; i <= n; i++) {
    if(i > n - i + 1) {
      sp[i] = sp[i-1] - (prefix_sum[i - 2] - prefix_sum[n - i]);
    } else {
      sp[i] = sp[i-1] + (prefix_sum[n - i] - prefix_sum[i - 2]);
    }
    res += sp[i] / (double) i;
    //printf("res is %f\n", res);
  }
  printf("%.7f\n", res);
  return 0;
}
