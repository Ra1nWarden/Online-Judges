#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstdlib>
#define MAXN 110000
#define INF 2e8

using namespace std;

int t1[MAXN], t2[MAXN], c[MAXN], sa[MAXN], ra[MAXN], str[MAXN], height[MAXN], wa[MAXN];
int n, w;

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

int half_div(int a, int b) {
  //cout << "half_div " << a << " and " << b << endl;
  if(a == b)
    return a;
  int startindex = 0;
  int endindex = startindex;
  int mid = (a + b) / 2 + 1;
  for(int i = 1; i <= n; i++) {
    if(height[i] >= mid) {
      endindex++;
    } else {
      set<int> dnas;
      for(int j = startindex; j <= endindex; j++) {
	dnas.insert(wa[sa[j]]);
      }
      if(dnas.size() > w / 2) {
	return half_div(mid, b);
      }
      startindex = i;
      endindex = startindex;
    }
  }
  return half_div(a, mid-1);
}

string restore_str(int s, int l) {
  string result = "";
  for(int i = s; i < s + l; i++) {
    result += (char) str[i];
  }
  return result;
}

int main() {
  string line;
  bool init = true;
  while(cin >> w && w) {
    if(!init)
      cout << endl;
    int maxlength = 0;
    n = 0;
    int sep = 160; // does not have to be the smallest among all chars
    getline(cin, line);
    if(w == 1) {
      getline(cin, line);
      cout << line << endl;
      continue;
    }

    for(int i = 0; i < w; i++) {
      if(i != 0) {
	wa[n] = -1;
	str[n++] = sep++;
      }
      getline(cin, line);
      maxlength = max(maxlength, (int)line.length());
      for(int j = 0; j < line.length(); j++) {
	wa[n] = i;
	str[n++] = line[j];
      }
    }
    str[n] = 0; // has to be null terminated: str[length of this string] = n
    da(262);
    
    // cout << "suffix array" << endl;
    // for(int i = 0; i <= n; i++) {
    //   cout << "sa[" << i << "]: " << sa[i] << endl;
    //   for(int j = sa[i]; j < n; j++)
    // 	cout << str[j] << " ";
    //   cout << endl;
    // }

    // for(int i = 1; i <= n; i++)
    //   cout << "height[" << i << "] -> " << height[i] << " : " << restore_str(sa[i], n - sa[i] + 1) << " and " << restore_str(sa[i-1], n - sa[i-1] + 1) << endl;
    
    int resultlength = half_div(0, maxlength);
    //cout << "resultlength is " << resultlength << endl;
    if(resultlength == 0) {
      cout << "?" << endl;
    } else {
      int startindex = 0;
      int endindex = startindex;
      set<string> outputs;
      for(int i = 1; i <= n; i++) {
	if(height[i] >= resultlength) {
	  endindex++;
	  //cout << "i is " << i << " start index is " << startindex << endl;
	}
	else {
	  set<int> dnas;
	  for(int j = startindex; j <= endindex; j++) {
	    if(wa[sa[j]] > -1)
	      dnas.insert(wa[sa[j]]);
	  }
	  if(dnas.size() > w / 2) {
	    outputs.insert(restore_str(sa[endindex], resultlength));
	    startindex++;
	    i = startindex;
	    endindex = startindex;
	  } else {
	    startindex = i;
	    i = startindex;
	    endindex = startindex;
	  }
	}
      }
      for(set<string>::iterator itr = outputs.begin(); itr != outputs.end(); itr++)
	cout << *itr << endl;
    }
    init = false;
  }
  return 0;
}
