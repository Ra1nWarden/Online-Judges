#include <iostream>
#include <set>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  int a[m][n];
  int b[m][n];
  for(int i= 0; i < m; i++) {
    for(int j= 0; j < n; j++)
      a[i][j] = 1;
  }
  for(int i= 0; i < m ; i++) {
    for(int j= 0; j < n; j++) {
      int x;
      cin >> x;
      b[i][j] = x;
      if(!x) {
	for(int k = 0; k < m; k++)
	  a[k][j] = 0;
	for(int k = 0; k < n; k++)
	  a[i][k] = 0;
      }
    }
  }
  bool valid = true;
  for(int i= 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      if(b[i][j]) {
	bool ok = false;
	for(int k= 0; k < m; k++) {
	  if(a[k][j]) {
	    ok = true;
	    break;
	  }
	}
	if(!ok) {
	  for(int k = 0; k < n; k++) {
	    if(a[i][k]) {
	      ok = true;
	      break;
	    }
	  }
	}
	valid = ok;
	if(!valid)
	  break;
      }
    }
    if(!valid)
      break;
  }

  cout << (valid ? "YES" : "NO") << endl;
  if(valid) {
    for(int i= 0 ; i < m; i++) {
      for(int j= 0; j < n; j++) {
	if(j != n-1)
	  cout << a[i][j] << " ";
	else
	  cout << a[i][j] << endl;
      }
    }
  }
  return 0;
}
