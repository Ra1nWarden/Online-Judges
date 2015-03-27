#include <cstdio>
#include <stack>
#include <cstring>
#define MAXN 105

using namespace std;

bool adjMat[MAXN][MAXN][MAXN];
bool visited[MAXN];

int n, m;

int main() {
  scanf("%d %d", &n, &m);
  memset(adjMat, false, sizeof adjMat);
  for(int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adjMat[a][b][c] = true;
    adjMat[b][a][c] = true;
  }
  int q;
  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    int res = 0;
    for(int j = 1; j <= m; j++) {
      memset(visited, false, sizeof visited);
      stack<int> s;
      s.push(start);
      visited[start] = true;
      while(!s.empty() && !visited[end]) {
	int next = s.top();
	s.pop();
	for(int k = 1; k <= n; k++) {
	  if(adjMat[next][k][j] && !visited[k]) {
	    visited[k] = true;
	    s.push(k);
	  }
	}
      }
      if(visited[end]) {
	res++;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
