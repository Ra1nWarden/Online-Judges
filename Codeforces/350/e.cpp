#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 500000;
const int maxm = 500000;
int n, m, p;
char seqs[maxn+5];
char commands[maxm+5];
int prevv[maxn+5];
int nextv[maxn+5];
int match[maxn+5];

int main() {
  scanf("%d%d%d\n", &n, &m, &p);
  scanf("%s\n", seqs+1);
  scanf("%s\n", commands);
  stack<int> s;
  nextv[0] = 1;
  prevv[n+1] = n;
  for(int i = 1; i <= n; i++) {
    if(seqs[i] == '(') {
      s.push(i);
    } else {
      match[i] = s.top();
      match[s.top()] = i;
      s.pop();
    }
    prevv[i] = i-1;
    nextv[i] = i+1;
  }
  for(int i = 0; i < m; i++) {
    char cmd = commands[i];
    if(cmd == 'L') {
      p = prevv[p];
    } else if(cmd == 'R') {
      p = nextv[p];
    } else if(cmd == 'D') {
      int matched = match[p];
      if(p < matched) {
	nextv[prevv[p]] = nextv[matched];
	prevv[nextv[matched]] = prevv[p];
	p = nextv[matched];
      } else {
	nextv[prevv[matched]] = nextv[p];
	prevv[nextv[p]] = prevv[matched];
	p = nextv[p];
      }
      if(p == n+1)
	p = prevv[p];
    }
  }
  p = nextv[0];
  while(p != n+1) {
    printf("%c", seqs[p]);
    p = nextv[p];
  }
  printf("\n");
  return 0;
}
