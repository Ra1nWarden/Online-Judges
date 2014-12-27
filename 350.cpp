#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int z, i, m, l;

int f(int x) {
  return (x * z + i) % m;
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
  int tc = 1;
  while(cin >> z >> i >> m >> l && (z || i || m || l)) {
    pair<int, int> result = FloydCycleFinding(f, l);
    printf("Case %d: %d\n", tc++, result.second);
  }
  return 0;
}
