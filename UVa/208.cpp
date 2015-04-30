#include <stack>
#include <cstdio>
#include <cstring>
#define MAXN 25

using namespace std;

int d;
bool adjMat[MAXN][MAXN];
bool visited[MAXN];
int v[MAXN];
int count;

void dfs(int node, int depth) {
  if(node == d) {
    count++;
    for(int i = 0; i < depth; i++) {
      if(i > 0)
	printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
    return;
  }
  for(int i = 1; i <= 21; i++) {
    if(!visited[i] && adjMat[node][i]) {
      visited[i] = true;
      v[depth] = i;
      dfs(i, depth+1);
      visited[i] = false;
    }
  }
}

int main() {
  int kase = 1;
  while(scanf("%d", &d) != EOF) {
    memset(adjMat, false, sizeof adjMat);
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF && (a || b)) {
      adjMat[a][b] = adjMat[b][a] = true;
    }
    memset(visited, false, sizeof visited);
    visited[1] = true;
    stack<int> s;
    s.push(1);
    while(!s.empty() && !visited[d]) {
      int next = s.top();
      s.pop();
      for(int i = 1; i <= 21; i++) {
	if(!visited[i] && adjMat[next][i]) {
	  visited[i] = true;
	  s.push(i);
	}
      }
    }
    printf("CASE %d:\n", kase++);
    if(!visited[d]) {
      printf("There are 0 routes from the firestation to streetcorner %d.\n", d);
    } else {
      memset(visited, false, sizeof visited);
      visited[1] = true;
      v[0] = 1;
      count = 0;
      dfs(1, 1);
      printf("There are %d routes from the firestation to streetcorner %d.\n", count, d);
    }
  }
  return 0;
}
