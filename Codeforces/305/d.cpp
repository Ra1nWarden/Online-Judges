#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

const int maxn = 200000;

int v[maxn+5];
int update[maxn+5];
int l[maxn+5];
int r[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  stack<int> s;
  for(int i = 1; i <= n; i++) {
    while(!s.empty()) {
      if(v[s.top()] >= v[i]) {
	s.pop();
      } else {
	break;
      }
    }
    if(s.empty()) {
      l[i] = 0;
    } else {
      l[i] = s.top();
    }
    s.push(i);
  }
  while(!s.empty())
    s.pop();
  for(int i = n; i >= 1; i--) {
    while(!s.empty()) {
      if(v[s.top()] >= v[i]) {
	s.pop();
      } else {
	break;
      }
    }
    if(s.empty()) {
      r[i] = n+1;
    } else {
      r[i] = s.top();
    }
    s.push(i);
  }
  memset(update, 0, sizeof update);
  for(int i = 1; i <= n; i++) {
    int ui = r[i] - l[i] - 1;
    update[ui] = max(update[ui], v[i]);
  }
  for(int i = n - 1; i > 0; i--) {
    update[i] = max(update[i], update[i+1]);
  }
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", update[i]);
  }
  printf("\n");
  return 0;
}
