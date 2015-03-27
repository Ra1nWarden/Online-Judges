#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
  int dist, index;
  Node() {};
  Node(int d, int i) : dist(i), index(i) {};
  bool operator<(const Node& b) const {
    return dist < b.dist;
  };
};

Node nodes[3];
int ranks[3];

int main() {
  int tc;
  scanf("%d", &tc);
  for(int i = 0 ;i < tc; i++) {
    int n;
    scanf("%d", &n);
    for(int j= 0; j < n;j++) {
      int maxdist = -1;
      for(int k = 0; k < 3; k++) {
	int thisjump;
	scanf("%d", &thisjump);
	maxdist = max(thisjump, maxdist);
      }
      nodes[j].dist = maxdist;
      nodes[j].index = j;
    }
    sort(nodes, nodes+n);
    for(int j = n; j >= 1; j--) {
      ranks[nodes[n - j].index] = j; 
    }
    for(int j = 0; j < n; j++) {
      if(j != 0)
	printf(" ");
      printf("%d", ranks[j]);
    }
    printf("\n");
  }
  return 0;
}
