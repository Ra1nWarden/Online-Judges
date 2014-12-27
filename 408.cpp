#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

int step, mod;

int f(int x) {
  return (x + step) % mod;
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
  while(cin >> step >> mod && (step || mod)) {
    pair<int, int> result = FloydCycleFinding(f, 0);
    cout << setw(10) << right << step;
    cout << setw(10) << right << mod;
    cout << "    " << (result.second == mod ? "Good Choice" : "Bad Choice") << endl;
    cout << endl;
  }
  return 0;
}
