#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 2e9

using namespace std;

int yang[3];
int monster[3];
int h, a, d;

int main() {
  scanf("%d %d %d", &yang[0], &yang[1], &yang[2]);
  scanf("%d %d %d", &monster[0], &monster[1], &monster[2]);
  scanf("%d %d %d", &h, &a, &d);
  if(monster[1] <= yang[2]) {
    printf("%d\n", (max(yang[1], monster[2] + 1) - yang[1]) * a);
    return 0;
  }
  int mincost = INF;
  for(int att = yang[1]; att <= monster[0] + monster[2]; att++) {
    if(att <= monster[2])
      continue;
    int cost = a * (att - yang[1]);
    //printf("att is %d\n", att);
    //printf("cost is %d\n", cost);
    if(cost > mincost)
      break;
    for(int def = yang[2]; def <= monster[1]; def++) {
      //printf("trying atk=%d def=%d\n", att, def);
      cost += d * (def - yang[2]);
      if(cost > mincost)
	break;
      int dmgdone = att - monster[2];
      int dmgreceived = monster[1] - def;
      int timekill = ceil((double) monster[0] / dmgdone); 
      int minhp = timekill * (monster[1] - def) + 1;
      cost += h * (max(0, minhp - yang[0]));
      mincost = min(mincost, cost);
    }
  }
  printf("%d\n", mincost == INF ? 0 : mincost);
  return 0;
}
