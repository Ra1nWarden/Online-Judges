#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int f(int x) {
  int result = 0;
  while(x > 0) {
    result += ((x % 10) * (x % 10));
    x /= 10;
  }
  return result;
}

pair<int, int> FloydCycleFinding(int (*f)(int), int x0) {
  int tortoise = f(x0), hare = f(f(x0));
  while(tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(f(hare));
  }
  int mu = 0;
  hare = tortoise;
  tortoise = x0;
  while(tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(hare);
    mu++;
  }
  int lambda = 1;
  hare = f(tortoise);
  while(tortoise != hare) {
    hare = f(hare);
    lambda++;
  }
  return make_pair(mu, lambda);
}

int main() {
  int tc;
  cin >> tc;
  for(int i = 0; i < tc; i++) {
    int x;
    cin >> x;
    pair<int, int> result = FloydCycleFinding(f, x);
    printf("Case #%d: %d is", i+1, x);
    if(result.second == 1) {
      printf(" a Happy number.\n");
    } else {
      printf(" an Unhappy number.\n");
    }
  }
  return 0;
}
