#include <cstdio>
#include <string>
#include <stack>
#include <cstring>
#include <cmath>
#include <vector>
#define MAXN 1005

using namespace std;

int n;
int xv[MAXN];
int yv[MAXN];
int rv[MAXN];
bool left[MAXN];
bool right[MAXN];
bool top[MAXN];
bool btm[MAXN];
const int w = 1000;
bool adjMat[MAXN][MAXN];
bool visited[MAXN];

int main() {
  while(scanf("%d", &n) != EOF) {
    memset(left, false, sizeof left);
    memset(right, false, sizeof right);
    memset(top, false, sizeof top);
    memset(btm, false, sizeof btm);
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d", &xv[i], &yv[i], &rv[i]);
      if(xv[i] <= rv[i])
	left[i] = true;
      if(xv[i] + rv[i] >= w)
	right[i] = true;
      if(yv[i] + rv[i] >= w)
	top[i] = true;
      if(yv[i] <= rv[i])
	btm[i] = true;
    }
    memset(adjMat, false, sizeof adjMat);
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	int sum_square = (xv[i] - xv[j]) * (xv[i] - xv[j]) + (yv[i] - yv[j]) * (yv[i] - yv[j]);
	int sum_rad = (rv[i] + rv[j]) * (rv[i] + rv[j]);
	if(sum_square <= sum_rad)
	  adjMat[i][j] = adjMat[j][i] = true;
      }
    }
    memset(visited, false, sizeof visited);
    stack<int> s;
    for(int i = 0; i < n; i++) {
      if(top[i]) {
	s.push(i);
	visited[i] = true;
      }
    }
    bool ok = true;
    vector<int> leftv;
    vector<int> rightv;
    while(!s.empty() && ok) {
      int u = s.top();
      s.pop();
      if(btm[u]) {
	ok = false;
	break;
      }
      if(left[u]) {
	leftv.push_back(u);
      }
      if(right[u]) {
	rightv.push_back(u);
      }
      for(int i = 0; i < n; i++) {
	if(!visited[i] && adjMat[u][i]) {
	  visited[i] = true;
	  s.push(i);
	}
      }
    }
    if(!ok)
      printf("IMPOSSIBLE\n");
    else {
      double l = 1000.00;
      for(int i = 0; i < leftv.size(); i++) {
	int ii = leftv[i];
	l = min(l, yv[ii] - sqrt(pow(rv[ii], 2) - pow(xv[ii], 2)));
      }
      double r = 1000.00;
      for(int i = 0; i < rightv.size(); i++) {
	int ii = rightv[i];
	r = min(r, yv[ii] - sqrt(pow(rv[ii], 2) - pow(1000 - xv[ii], 2)));
      }
      printf("0.00 %.2lf 1000.00 %.2lf\n", l, r);
    }
  }
  return 0;
}
