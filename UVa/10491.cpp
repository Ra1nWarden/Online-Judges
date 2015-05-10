#include <cstdio>

using namespace std;

int cow, car, show;

int main() {
  while(scanf("%d %d %d", &cow, &car, &show) != EOF) {
    double change = (car * 1.0 / (cow + car)) * ((car - 1) * 1.0 / (car + cow - show - 1)) + (cow * 1.0 / (cow + car)) * (car * 1.0 / (car + cow - show - 1));
    printf("%.5f\n", change);
  }
  return 0;
}
