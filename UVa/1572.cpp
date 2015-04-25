#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 52

using namespace std;

int id(char c, char sgn) {
  return (c - 'A') * 2 + (sgn == '+' ? 0 : 1);
}

int adjMat[MAXN][MAXN];

void addEdge(char a1, char a2, char b1, char b2) {
  if(a1 == '0' || b1 == '0')
    return;
  int u = id(a1, a2)^1;
  int v = id(b1, b2);

  adjMat[u][v] = 1;
}

int visited[MAXN];

bool dfs(int u) {
  visited[u] = -1;
  for(int v = 0; v < 52; v++) {
    if(adjMat[u][v]) {
      if(visited[v]  < 0)
	return true;
      else if(!visited[v] && dfs(v))
	return true;
    }
  }
  visited[u] = 1;
  return false;
}

bool find_cycle() {
  memset(visited, 0, sizeof visited);
  for(int i = 0; i < 52; i++) {
    if(!visited[i]) {
      if(dfs(i)) {
	return true;
      }
    }
  }
  return false;
}

int main() {
  int n;
  while(scanf("%d\n", &n) != EOF) {
    memset(adjMat, 0, sizeof adjMat);
    while(n--) {
      char square[10];
      scanf("%s", square);
      for(int i = 0; i < 4; i++) {
	for(int j = 0; j < 4; j++) {
	  if(i != j) {
	    addEdge(square[i*2], square[i*2+1], square[j*2], square[j*2+1]);
	  }
	}
      }
    }
    if(find_cycle())
      printf("unbounded\n");
    else
      printf("bounded\n");
  }
  return 0;
}
