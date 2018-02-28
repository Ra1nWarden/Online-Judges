#include <cstdio>
#include <string>
#include <cstring>
#define MAXN 1010

using namespace std;

struct SuffixArray {
  int t1[MAXN], t2[MAXN], c[MAXN], ra[MAXN], sa[MAXN], height[MAXN], str[MAXN];
  int n;
  SuffixArray(string line);
  SuffixArray();
  void BuildArrayDoubleAlgorithm(int m);
};

char str[MAXN];

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", str);
    SuffixArray sa(str);
    sa.BuildArrayDoubleAlgorithm(91);
    int ans = 0;
    int len = strlen(str);
    for(int i = 1; i <= len; i++) {
      ans += len - sa.sa[i] - sa.height[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}

SuffixArray::SuffixArray(string line) {
  for(int i = 0; i < line.length(); i++) {
    str[i] = line[i];
  }
  str[line.length()] = 0;
  n = line.length();
}

void SuffixArray::BuildArrayDoubleAlgorithm(int m) {
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
