#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#define MAXL 30
#define MAXN 30

using namespace std;

int n, m, ni;
map<string, int> names;
map<int, string> rev;
char a[MAXL], b[MAXL];
bool d[MAXN][MAXN];
bool visited[MAXN];

int main() {
  int kase = 1;
  while(scanf("%d %d\n", &n,  &m) != EOF && (n || m)) {
    if(kase > 1)
      printf("\n");
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	d[i][j] = i == j;
      }
    }
    names.clear();
    rev.clear();
    ni = 0;
    for(int i = 0; i < m; i++) {
      scanf("%s %s\n", a, b);
      string astr(a);
      string bstr(b);
      if(names.count(astr) == 0) {
	names[astr] = ni;
	rev[ni] = astr;
	ni++;
      }
      if(names.count(bstr) == 0) {
	names[bstr] = ni;
	rev[ni] = bstr;
	ni++;
      }
      d[names[astr]][names[bstr]] = true;
    }
    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
	}
      }
    }
    memset(visited, false, sizeof visited);
    printf("Calling circles for data set %d:\n", kase++);
    for(int i = 0; i < n; i++) {
      if(!visited[i]) {
	vector<int> prints;
	prints.push_back(i);
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while(!q.empty()) {
	  int next = q.front();
	  q.pop();
	  for(int j = 0; j < n; j++) {
	    if(!visited[j] && d[next][j] && d[j][next]) {
	      visited[j] = true;
	      prints.push_back(j);
	      q.push(j);
	    }
	  }
	}
	for(int j = 0; j < prints.size(); j++) {
	  if(j > 0)
	    printf(", ");
	  printf("%s", rev[prints[j]].c_str());
	}
	printf("\n");
      }
    }
  }
  return 0;
}
