#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#define INF 2000000000

using namespace std;

int count[10];

vector<int> solve(int n) {
  memset(count, 0, sizeof count);
  int ci = 0;
  while(n > 0) {
    count[ci++] = (n % 10);
    n /= 10;
  }
  vector<int> ans;
  while(true) {
    int minCount = INF;
    for(int i = 0; i < ci; i++) {
      if(count[i] != 0) {
	minCount = min(minCount, count[i]);
      }
    }
    if(minCount == INF)
      break;
    int number = 0;
    int base = 1;
    for(int i = 0; i < ci; i++) {
      if(count[i] != 0) {
	number += base;
      }
      base *= 10;
    }
    for(int i = 0; i < minCount; i++) {
      ans.push_back(number);
    }
    for(int i = 0; i < ci; i++) {
      if(count[i] > 0)
	count[i] -= minCount;
    }
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans = solve(n);
  int sum = 0;
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    if(i > 0)
      printf(" ");
    printf("%d", ans[i]);
    sum += ans[i];
  }
  printf("\n");
  if(sum != n) {
    while(true) {

    }
  }
  return 0;
}
