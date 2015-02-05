#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstdio>
#define INF 2e8

using namespace std;

const static string tdp_end = "END TDP CODEBASE";
const static string jcn_end = "END JCN CODEBASE";

const int MAXN = 1000002;
int t1[MAXN], t2[MAXN], c[MAXN], rankk[MAXN], height[MAXN], sa[MAXN];
string str;

bool cmp(int *r, int a, int b, int l) {
  return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int m) {
  int n = str.length();
  n++;
  int i, j, p, *x = t1, *y = t2;
  for(i = 0; i < m; i++) c[i] = 0;
  for(i = 0; i < n; i++) c[x[i] = str[i]]++;
  for(i = 1; i < m; i++) c[i] += c[i-1];
  for(i = n-1; i>=0; i--) sa[--c[x[i]]] = i;
  for(j = 1; j <= n; j <<= 1) {
    p = 0;
    for(i = n-j; i <n; i++) y[p++] = i;
    for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[y[i]]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1;
    x[sa[0]] = 0;
    for(i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
    if(p >= n)
      break;
    m = p;
  }
  int k = 0; 
  n--;
  for(i = 0; i <= n; i++)
    rankk[sa[i]] = i;
  for(i = 0; i < n; i++) {
    if(k)
      k--;
    j = sa[rankk[i] - 1];
    while(str[i+k] == str[j+k])
      k++;
    height[rankk[i]] = k;
  }
}

struct PrintState {
  int length;
  int position;
  string repeated;
  PrintState(int l, int p) : length(l), position(p) {};
  bool operator<(const PrintState& another) const {
    if(length != another.length)
      return length < another.length;
    return position > another.position;
  };
};

int main() {
  int n;
  string line;
  int tc = 1;
  while(cin >> n && n) {
    getline(cin, line);
    getline(cin, line); // begin tdp codebase
    string a = "";
    while(getline(cin, line)) {
      if(line == tdp_end)
	break;
      a += line;
      a += "\n";
    }
    getline(cin, line); // begin jcn codebase
    string b = "";
    while(getline(cin, line)) {
      if(line == jcn_end)
	break;
      b += line;
      b += "\n";
    }
    str = a + '$' + b;
    da(261);

#ifdef _DEBUG
    cout << "a length is " << a.length() << endl;
    cout << "b length is " << b.length() << endl;
    cout << "str length is " << str.length() << endl;
    cout << "suffix array for " << endl;
    cout << str << endl;
    for(int i = 0; i <= str.length(); i++)
      cout << "sa[" << i << "] -> " << sa[i] << ":" << str.substr(sa[i]) << endl;
    cout << "end of suffix array" << endl;
#endif

#ifdef _DEBUG
    cout << "height array" << endl;
    for(int i = 0; i <= str.length(); i++) {
      cout << "height[" << i << "] -> " << height[i] << endl;
    }
    cout << "end of height array" << endl;
#endif

    int v[MAXN];
    memset(v, 0, sizeof v);
    int Min = -1;
    for(int i = 1; i <= str.length(); i++) {
      if(sa[i] < a.length()) Min = INF;
      else if (sa[i] > a.length()) {
	if(Min == -1)
	  continue;
	Min = min(Min, height[i]);

#ifdef _DEBUG
	cout << "forward debug" << endl;
	if(sa[i] - a.length() - 1 == 4) {
	  cout << "original array entry " << v[4] << endl;
	  cout << "Min is " <<  Min << endl;
	  cout << "i is " << i << endl;
	  cout << "height[i] is " << height[i] << endl; 
	  cout << "height[i] string is " << str.substr(sa[i]) << endl;
	  cout << "height[i-1] string is " << str.substr(sa[i-1]) << endl;
	  cout << "v[4] is " << v[4] << endl;
	}
#endif

	v[sa[i] - a.length() - 1] = max(v[sa[i] - a.length() - 1], Min);

      }
    }

#ifdef _DEBUG
    cout << "after forward scan inspecting v" << endl;
    for(int i = 0; i < b.length(); i++) {
      cout << i << ": " << v[i] << endl;
    }
#endif

    Min = -1;
    for(int i = str.length(); i >= 1; i--) {
      if(sa[i] < a.length())
	Min = INF;
      else if (sa[i] > a.length()) {
	if(Min == -1)
	  continue;
	Min = min(Min, height[i+1]);

#ifdef _DEBUG
	cout << "backward debug" << endl;
	if(sa[i] - a.length() - 1 == 4) {
	  cout << "original array entry " << v[4] << endl;
	  cout << "Min is " <<  Min << endl;
	  cout << "i is " << i << endl;
	  cout << "height[i+1] is " << height[i+1] << endl;
	  cout << "height[i+1] string is " << str.substr(sa[i+1]) << endl;
	  cout << "height[i] string is " << str.substr(sa[i]) << endl;
	  cout << "v[4] is " << v[4] << endl;
	}
#endif

	v[sa[i] - a.length() - 1] = max(Min, v[sa[i] - a.length() - 1]);
      }
    }

    priority_queue<PrintState> pq;
    
#ifdef _DEBUG
    cout << "after backawards scan inspecting v" << endl;
    for(int i = 0; i < b.length(); i++) {
      cout << i << ": " << v[i] << endl;;
    }
#endif

    int r = -1;
    for(int i = 0; i < b.length(); i++) {
      if(v[i] + i <= r)
	continue;
      if(v[i] == 0)
	continue;
      PrintState ps(v[i], i);
      ps.repeated = b.substr(i, v[i]);
      pq.push(ps);
      r = i + v[i];
    }
    if(tc != 1)
      printf("\n");
    printf("CASE %d\n", tc++);
    int seg = 1;
    int printed = 0;
    while(!pq.empty() && printed < n) {
      PrintState next = pq.top();
      pq.pop();
      printf("INFRINGING SEGMENT %d LENGTH %d POSITION %d\n%s\n", seg++, next.length, next.position, next.repeated.c_str());
      printed++;
    }
  }
  return 0;
}
