#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#define MAXN 100005

using namespace std;

int n, m;

void generate_primes(int num, vector<int>& primes) {
  for(int i = 2; i <= sqrt(num+0.5); i++) {
    if(num % i == 0) {
      primes.push_back(i);
      while(num % i == 0)
	num /= i;
    }
  }
  if(num > 1)
    primes.push_back(num);
}

bool bad[MAXN];

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    vector<int> primes;
    generate_primes(m, primes);
    memset(bad, true, sizeof bad);
    for(int i = 0; i < primes.size(); i++) {
      int min_cnt = 0;
      int num = m;
      while(num % primes[i] == 0) {
	num /= primes[i];
	min_cnt++;
      }
      num = 1;
      int cnt = 0;
      for(int j = 1; j < n; j++) {
	num = n - j;
	while(num % primes[i] == 0) {
	  num /= primes[i];
	  cnt++;
	}
	num = j;
	while(num % primes[i] == 0) {
	  num /= primes[i];
	  cnt--;
	}
	if(cnt < min_cnt) {
	  //printf("prime is %d cnt is %d min cnt is %d j=%d\n", primes[i], cnt, min_cnt, j);
	  bad[j] = false;
	}
      }
    }
    vector<int> ans;
    for(int i = 1; i < n; i++)
      if(bad[i])
	ans.push_back(i+1);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
      if(i > 0) {
	printf(" ");
      }
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
