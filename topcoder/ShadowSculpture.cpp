#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 15

using namespace std;

// @begin_lib
// @end_lib

struct Node {
  int x, y, z;
};

class ShadowSculpture {
private:
  bool sculpture[MAXN][MAXN][MAXN];
  bool visited[MAXN][MAXN][MAXN];
  const int dx[6] = {1,-1,0,0,0,0};
  const int dy[6] = {0,0,1,-1,0,0};
  const int dz[6] = {0,0,0,0,1,-1};
  int n;
public:
  vector<Node> dfs(int i, int j, int k) {
    vector<Node> res;
    visited[i][j][k] = true;
    stack<Node> s;
    Node start;
    start.x = i;
    start.y = j;
    start.z = k;
    s.push(start);
    while(!s.empty()) {
      Node next = s.top();
      s.pop();
      res.push_back(next);
      //printf("dfs next = %d %d %d\n", next.x, next.y, next.z);
      for(int d = 0; d < 6; d++) {
	int ii = next.x + dx[d];
	int jj = next.y + dy[d];
	int kk = next.z + dz[d];
	if(ii > -1 && ii < n && jj > -1 && jj < n && kk > -1 && kk < n && sculpture[ii][jj][kk] && !visited[ii][jj][kk]) {
	  visited[ii][jj][kk] = true;
	  Node nn;
	  nn.x = ii;
	  nn.y = jj;
	  nn.z = kk;
	  s.push(nn);
	}
      }
    }
    return res;
  }

  bool check(vector<Node> nodes, vector <string> XY, vector <string> YZ, vector <string> ZX) {
    for(int i = 0; i < XY.size(); i++) {
      for(int j = 0; j < XY[0].length(); j++) {
	if(XY[i][j] == 'Y') {
	  bool ok = false;
	  for(int ni = 0; ni < nodes.size(); ni++) {
	    int x = nodes[ni].x;
	    int y = nodes[ni].y;
        
	    if(x == i && y == j) {
	      ok = true;
	      break;
	    }
	  }
	  if(!ok)
	    return false;
	} else {
	  bool ok = true;
	  for(int ni = 0; ni < nodes.size(); ni++) {
	    int x = nodes[ni].x;
	    int y = nodes[ni].y;

	    if(x == i && y == j) {
	      ok = false;
	      break;
	    }
	  }
	  if(!ok)
	    return false;
	}
      }
    }
    
    for(int j = 0; j < YZ.size(); j++) {
      for(int k = 0; k < YZ[0].length(); k++) {
	if(YZ[j][k] == 'Y') {
	  bool ok = false;
	  for(int ni = 0; ni < nodes.size(); ni++) {

	    int y = nodes[ni].y;
	    int z = nodes[ni].z;
	    if(y == j && z == k) {
	      ok = true;
	      break;
	    }
	  }
	  if(!ok)
	    return false;
	} else {
	  bool ok = true;
	  for(int ni = 0; ni < nodes.size(); ni++) {

	    int y = nodes[ni].y;
	    int z = nodes[ni].z;
	    if(y == j && z == k) {
	      ok = false;
	      break;
	    }
	  }
	  if(!ok)
	    return false;
	}	
      }
    }
    
    for(int k = 0; k < ZX.size(); k++) {
      for(int i = 0; i < ZX[0].length(); i++) {
	if(ZX[k][i] == 'Y') {
	  bool ok = false;
	  for(int ni = 0; ni < nodes.size(); ni++) {
	    int x = nodes[ni].x;

	    int z = nodes[ni].z;
	    if(z == k && x == i) {
	      ok = true;
	      break;
	    }
	  }
	  if(!ok)
	    return false;
	} else {
	  bool ok = true;
	  for(int ni = 0; ni < nodes.size(); ni++) {
	    int x = nodes[ni].x;

	    int z = nodes[ni].z;
	    if(z == k && x == i) {
	      ok = false;
	      break;
	    }
	  }
	  if(!ok)
	    return false;	
	}
      }
    }

    return true;
  }
  
  string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
    memset(sculpture, true, sizeof sculpture);
    n = XY.size();
    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  if(XY[i][j] == 'N' || YZ[j][k] == 'N' || ZX[k][i] == 'N') {
	    //printf("painting %d %d %d to true\n", i, j, k);
	    sculpture[i][j][k] = false;
	  }
	}
      }
    }
    


    memset(visited, false, sizeof visited);
    int cn = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < n; k++) {
	  if(sculpture[i][j][k] && !visited[i][j][k]) {
	    cn++;
	    vector<Node> components = dfs(i, j, k);
	    if(check(components, XY, YZ, ZX))
	      return "Possible";
	  }
	}
      }
    }
    
    if(cn == 0) {

      for(int i = 0; i < n; i++) {
	for(int j= 0; j < n; j++) {
	  if(XY[i][j] == 'Y')
	    return "Impossible";
	}
      }

      for(int j = 0; j < n; j++) {
	for(int k= 0; k < n; k++) {
	  if(YZ[j][k] == 'Y')
	    return "Impossible";
	}
      }

      for(int k = 0; k < n; k++) {
	for(int i = 0; i < n; i++) {
	  if(ZX[k][i] == 'Y')
	    return "Impossible";
	}
      }

      return "Possible";
    }
    
    
    return "Impossible";
  }
};

// @begin_tests
void _run_test(vector< string > XY, vector< string > YZ, vector< string > ZX, string res_expected, int test_no) {
string tc_res = (new ShadowSculpture)->possible(XY, YZ, ZX);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << '"' << res_expected << '"';
cout << endl << "got: ";
cout << '"' << tc_res << '"';
cout << endl;
}
}
int main() {
vector< string > XY;
vector< string > YZ;
vector< string > ZX;
string res_expected;
{string tmpa[] = {"YN", "NN"};
XY.assign(tmpa, tmpa + 2);}
{string tmpa[] = {"YN", "NN"};
YZ.assign(tmpa, tmpa + 2);}
{string tmpa[] = {"YN", "NN"};
ZX.assign(tmpa, tmpa + 2);}
res_expected = "Possible";
_run_test(XY, YZ, ZX, res_expected, 0);
{string tmpa[] = {"YN", "NY"};
XY.assign(tmpa, tmpa + 2);}
{string tmpa[] = {"YN", "NY"};
YZ.assign(tmpa, tmpa + 2);}
{string tmpa[] = {"YN", "NY"};
ZX.assign(tmpa, tmpa + 2);}
res_expected = "Impossible";
_run_test(XY, YZ, ZX, res_expected, 1);
{string tmpa[] = {"YYY", "YNY", "YYY"};
XY.assign(tmpa, tmpa + 3);}
{string tmpa[] = {"YYY", "YNY", "YYY"};
YZ.assign(tmpa, tmpa + 3);}
{string tmpa[] = {"YYY", "YNY", "YYY"};
ZX.assign(tmpa, tmpa + 3);}
res_expected = "Possible";
_run_test(XY, YZ, ZX, res_expected, 2);
{string tmpa[] = {"YYY", "YNY", "YYY"};
XY.assign(tmpa, tmpa + 3);}
{string tmpa[] = {"NYY", "YNY", "YYY"};
YZ.assign(tmpa, tmpa + 3);}
{string tmpa[] = {"YYY", "YNY", "YYN"};
ZX.assign(tmpa, tmpa + 3);}
res_expected = "Impossible";
_run_test(XY, YZ, ZX, res_expected, 3);
{string tmpa[] = {"N"};
XY.assign(tmpa, tmpa + 1);}
{string tmpa[] = {"N"};
YZ.assign(tmpa, tmpa + 1);}
{string tmpa[] = {"N"};
ZX.assign(tmpa, tmpa + 1);}
res_expected = "Possible";
_run_test(XY, YZ, ZX, res_expected, 4);
}
// @end_tests

// Born in Emacs
