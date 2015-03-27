#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 10005

using namespace std;

bool visited[2 * MAXN];
typedef pair<int, int> ii;
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  if(m == n) {
    printf("0\n");
    return 0;
  }
  memset(visited, false, sizeof visited);
  queue<ii> q;
  ii start;
  start.first = n;
  start.second = 0;
  q.push(start);
  visited[n] = true;
  while(!q.empty()) {
    ii next = q.front();
    q.pop();
    int num = next.first;
    int step = next.second;
    //printf("num is %d step is %d\n", num, step);
    // mult
    if(num < m) {
      int newnum = num * 2;
      if(newnum == m) {
	printf("%d\n", step + 1);
	return 0;
      }
      if(!visited[newnum]) {
	ii nextelem;
	nextelem.first = newnum;
	nextelem.second = step + 1;
	visited[newnum] = true;
	q.push(nextelem);
      }
    }
    if(num > 1) {
      int newnum = num - 1;
      if(newnum == m) {
	printf("%d\n", step + 1);
	return 0;
      }
      if(!visited[newnum]) {
	ii nextelem;
	nextelem.first = newnum;
	nextelem.second = step + 1;
	visited[newnum] = true;
	q.push(nextelem);
      }
    }
  }
  return 0;
}
