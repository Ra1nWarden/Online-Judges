#include <iostream>
#include <sstream>
#define INF 1009000001
#define MAXN 100005

using namespace std;

int v[MAXN];

// a < b
int findStart(int a, int b, int n) {
  //cout << "find start " << a << " " << b << " " << n << endl;
  if(b - a - 1 < n) {
    //cout << "findstart if " << b - a - 1 << endl;
    return INF;
  }
  else if(a > 0)
    return a + 1;
  else if(b < 0)
    return b - n;
  else
    return max(a+1, (-n) / 2);
}

int main() {
  int n, k;
  cin >> n >> k >> ws;
  for(int i = 0; i < n; i++) {
    string nstr;
    cin >> nstr;
    if(nstr[0] == '?')
      v[i] = INF;
    else {
      stringstream ss(nstr.c_str());
      ss >> v[i];
    }
  }
  bool ok = true;
  for(int i = 0; i < k; i++) {
    int starti, endi;
    bool started = false;
    for(int j = i; j < n; j+=k) {
      if(!started && j > i && v[j] <= v[j-k]) {
	ok = false;
	break;
      }
      if(v[j] == INF && !started) {
	started = true;
	starti = j;
      } 
      if((v[j] != INF || j + k >= n) && started){
	endi = v[j] == INF ? j : j - k;
	started = false;
	int len = (endi - starti) / k + 1;
	int startfill;
	if(starti - k < 0 && endi + k >= n) {
	  //cout << "if" << endl;
	  //cout << "starti " << starti << " endi " << endi << " " << len << endl;
	  startfill = findStart(-INF, INF, len);
	  //cout << "startfill is " << startfill << endl;
	} else if(starti - k < 0) {
	  //cout << "else if 1" << endl;
	  startfill = findStart(-INF, v[endi+k], len);
	} else if(endi + k >= n) {
	  //cout << "else if 2" << endl;
	  startfill = findStart(v[starti-k], INF, len);
	} else {
	  //cout << "else" << endl;
	  startfill = findStart(v[starti-k], v[endi+k], len);
	}
	if(startfill == INF) {
	  ok = false;
	  break;
	} else {
	  for(int ii = starti; ii <= endi; ii+=k)
	    v[ii] = startfill++;
	}
      }
    }
    if(!ok)
      break;
  }
  if(ok) {
    for(int i=  0; i < n; i++) {
      if(i != 0)
	cout << " ";
      cout << v[i];
    }
    cout << endl;
  } else {
    cout << "Incorrect sequence" << endl;
  }
  return 0;
}
