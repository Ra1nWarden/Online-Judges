#include <cstdio>

using namespace std;

int sides[6];

int calc(int side) {
  return side * (2 + (side - 1) * 2) / 2;
}

int main() {
  for(int i = 0; i < 6; i++)
    scanf("%d", &sides[i]);
  int side = sides[0] + sides[1] + sides[2];
  printf("%d\n", calc(side) - calc(sides[0]) - calc(sides[2]) - calc(sides[4]));
  return 0;
}
