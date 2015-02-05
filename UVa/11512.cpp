#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAXN 1005

using namespace std;

int t1[MAXN], t2[MAXN], c[MAXN], sa[MAXN], ra[MAXN], str[MAXN], height[MAXN];
int n;

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
    if(p >= n)
      break;
    m = p;
  }
  int k = 0;
  n--;
  for(i = 0; i <= n; i++) ra[sa[i]] = i;
  for(i = 0; i < n; i++) {
    if(k)
      k--;
    j = sa[ra[i] - 1];
    while(str[i+k] == str[j+k])
      k++;
    height[ra[i]] = k;
  }
}

int main() {
  int w;
  cin >> w;
  string line;
  getline(cin, line);
  for(int i = 0; i < w; i++) {
    getline(cin, line);
    n = 0;
    for(int j = 0; j < line.length(); j++) {
      str[n++] = line[j];
    }
    str[n] = 0;
    da('V');
#ifdef _DEBUG
    cout << "suffix array" << endl;
    for(int i = 0; i <= n; i++)
      cout << "sa[" << i << "] -> " << sa[i] << " : " << line.substr(sa[i]) << endl;
    cout << "height array" << endl;
    for(int i = 1; i <= n; i++) {
      cout << "height[" << i << "] -> " << height[i] << " : " << line.substr(sa[i]) << " vs " << line.substr(sa[i-1]) << endl;
    }
#endif
    string resultstr = "";
    int resultlen = 0;
    int resultcounter = 0;
    for(int j = 1; j <= n; j++) {
      if(height[j] > resultlen) {
	resultstr = line.substr(sa[j], height[j]);
	resultlen = height[j];
	resultcounter = 1;
      } else if (height[j] == resultlen) {
	string newstr = line.substr(sa[j], height[j]);
	if(newstr < resultstr) {
	  resultstr = newstr;
	  resultcounter = 1;
	}
	else if (newstr == resultstr)
	  resultcounter++;
      }
    }
    if(resultlen > 0)
      printf("%s %d\n", resultstr.c_str(), resultcounter+1);
    else
      printf("No repetitions found!\n");
  }
  return 0;
}
