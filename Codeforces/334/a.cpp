#include <cstdio>
#include <algorithm>

using namespace std;

int points[5] = {500, 1000, 1500, 2000, 2500};
int time[5];
int wrong[5];
int hs, hf;

int main() {
  for(int i = 0; i < 5; i++)
    scanf("%d", &time[i]);
  for(int i = 0; i < 5; i++)
    scanf("%d", &wrong[i]);
  scanf("%d%d", &hs, &hf);
  int total = 0;
  for(int i = 0; i < 5; i++) {
    int p1 = points[i] / 10 * 3;
    int p2 = points[i] - points[i] / 250 * time[i] - 50 * wrong[i];
    total += max(p1, p2);
  }
  total += 100 * hs;
  total -= 50 * hf;
  printf("%d\n", total);
  return 0;
}
