#include <cstdio>
#include <algorithm>

using namespace std;

const int maxl = 10;

struct Node {
  int region, score;
  char name[maxl+5];
  Node() {}
  bool operator<(const Node& rhs) const {
    if(region != rhs.region)
      return region < rhs.region;
    if(score != rhs.score)
      return score > rhs.score;
    return false;
  } 
};

const int maxn = 100000;
int n, m;
Node nodes[maxn];

int main() {
  scanf("%d%d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s %d %d\n", nodes[i].name, &nodes[i].region, &nodes[i].score);
  }
  sort(nodes, nodes + n);
  int idx = 0;
  for(int cur = 1; cur <= m; cur++) {
    while(nodes[idx].region != cur)
      idx++;
    if(idx + 2 < n && nodes[idx + 2].region == cur && nodes[idx + 2].score == nodes[idx + 1].score) {
      printf("?\n");
    } else {
      printf("%s %s\n", nodes[idx].name, nodes[idx+1].name);
    }
  }
  return 0;
}
