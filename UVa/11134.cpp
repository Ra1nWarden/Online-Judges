#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5005

using namespace std;

struct Node {
  int xl, yl, xr, yr;
  int index;
  Node() {}
};

Node nodes[MAXN];
int n;
int ansx[MAXN];
int ansy[MAXN];
bool usedx[MAXN];
bool usedy[MAXN];

bool cmpx(Node& a, Node& b) {
  if(a.xr != b.xr)
    return a.xr < b.xr;
  else
    return a.xl < b.xl;
}

bool cmpy(Node& a, Node& b) {
  if(a.yr != b.yr)
    return a.yr < b.yr;
  else
    return a.yl < b.yl;
}

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d %d", &nodes[i].xl, &nodes[i].yl, &nodes[i].xr, &nodes[i].yr);
      nodes[i].index = i;
    }
    memset(usedx, false, sizeof usedx);
    memset(usedy, false, sizeof usedy);
    bool possible = true;
    sort(nodes, nodes+n, cmpx);
    for(int i = 0; i < n; i++) {
      Node& next = nodes[i];
      bool ok = false;
      for(int j = next.xl; j <= next.xr; j++) {
	if(!usedx[j]) {
	  ansx[next.index] = j;
	  usedx[j] = true;
	  ok = true;
	  break;
	}
      }
      if(!ok) {
	possible = false;
	break;
      }
    }
    if(possible) {
      sort(nodes, nodes+n, cmpy);
      for(int i = 0; i < n; i++) {
	Node& next = nodes[i];
	bool ok = false;
	for(int j = next.yl; j <= next.yr; j++) {
	  if(!usedy[j]) {
	    ansy[next.index] = j;
	    usedy[j] = true;
	    ok = true;
	    break;
	  }
	}
	if(!ok) {
	  possible = false;
	  break;
	}
      }
    }
    if(!possible)
      printf("IMPOSSIBLE\n");
    else {
      for(int i = 0; i < n; i++) {
	printf("%d %d\n", ansx[i], ansy[i]);
      }
    }
  }
  return 0;
}
