#include <cstdio>
#include <cstring>
#include <map>
#include <map>

using namespace std;

map<int, int> height;
int n, m;

template <class T>
inline bool scan_d(T &ret) {
  char c;
  int sgn;
  if(c=getchar(), c==EOF)
    return 0;
  while(c!='-'&&(c<'0'||c>'9'))
    c=getchar();
  sgn = (c == '-')?-1 : 1;
  ret= (c == '-')?0:(c-'0');
  while(c=getchar(),c>='0'&&c<='9')
    ret = ret* 10 + (c - '0');
  ret*=sgn;
  return 1;
}

inline void out(int x) {
  if(x > 9)
    out(x/10);
  putchar(x%10+'0');
}

int main() {
  while(scan_d(n) && scan_d(m)) {
    for(int i = 0; i < n; i++) {
      int h;
      scan_d(h);
      //printf("h is %d\n", h);
      if(height.count(h) == 0) {
	height[h] = 1;
	//printf("initializing %d to 1\n", h);
      }
      else {
	height[h] = height[h]+1;
	//printf("updating %d to %d\n", h, height[h]);
      }
    }
    for(int i = 0; i < m; i++) {
      int shoot;
      scan_d(shoot);
      //printf("shoot %d\n",shoot);
      out(height.count(shoot) ? height[shoot] : 0);
      putchar('\n');
      height[shoot] = 0;
    }
  }
  return 0;
}
