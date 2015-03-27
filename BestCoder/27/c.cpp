#include <cstdio>
#include <map>
#define MAXN 100005

using namespace std;

int t1[MAXN], t2[MAXN], c[MAXN], ra[MAXN], sa[MAXN], height[MAXN], str[MAXN];
int n;

map<double, int> dict;

void da(int m) {
  n++;
  int i, j, p, *x = t1, *y = t2;
  for(i = 0; i < m; i++) c[i] = 0;
  for(i = 0; i < n; i++) c[x[i] = str[i]]++;
  for(i = 1; i < m; i++) c[i] += c[i-1];
  for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
  for(j = 1; j <= n; j <<= 1) {
    p = 0;
    for(i = n-j; i < n; i++) y[p++] = i;
    for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[y[i]]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1; x[sa[0]] = 0;
    for(i = 1; i < n; i++)
      x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? p - 1 : p++;
    if(p >= n) break;
    m = p;
  }
  int k = 0;
  n--;
  for(i = 0; i <= n; i++) ra[sa[i]] = i;
  for(i = 0; i < n; i++) {
    if(k) k--;
    j = sa[ra[i] - 1];
    while(str[i+k] == str[j+k]) k++;
    height[ra[i]] = k;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 0; et < tc; et++) {
    dict.clear();
    int ri = 1;
    int m;
    scanf("%d %d", &n, &m);
    n--; // length of the array is actually one less
    int prev;
    int next;
    for(int i = 0; i <= n; i++) {
      if(i == 0) {
	scanf("%d", &prev);
      } else {
	scanf("%d", &next);
	double r = (double) next / prev;
	if(dict.count(r) == 0)
	  str[i-1] = (dict[r] = ri++);
	else
	  str[i-1] = dict[r];
      }
    }
    str[n] = 0;
    da(ri+1);
    for(int i = 0; i < m; i++) {
      int l;
      scanf("%d", &l);
      // I just realized suffix array may not work for this problem
    }
  }

  return 0;
}
