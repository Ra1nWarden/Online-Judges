#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int fibs[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733};
int n = 45;
map<int, bool> m;

bool check(int x) {
  if(m.count(x))
    return m[x];
  for(int i = 0; i < 45; i++) {
    if(fibs[i] == x) 
      return m[x] = true;
  }
  double lim = sqrt(x);
  bool suc = false;
  for(int i = 3; i < 45; i++) {
    if(fibs[i] > lim)
      break;
    if(x % fibs[i] == 0) {
      suc = check(x / fibs[i]);
    }
    if(suc)
      return m[x] = true;
  }
  return m[x] = false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int i = 0; i < tc; i++) {
    int tcase;
    scanf("%d", &tcase);
    printf("%s\n", check(tcase) ? "Yes" : "No");
  }
}
