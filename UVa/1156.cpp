#include <iostream>
#include <sstream>
#include <cstring>
#include <stack>

using namespace std;

typedef pair<int, int> Point;
const int maxn = 1024;
Point mat[maxn+1][maxn+1];
Point cpy[maxn+1][maxn+1];
bool visited[maxn+1][maxn+1];
int n;

void init() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      mat[i][j] = make_pair(i, j);
    }
  }
}

void id(bool rev) {
  return;
}

void rot(bool rev) {
  if(rev) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n-1-i; j++) {
	swap(mat[i][j], mat[n-1-j][n-1-i]);
      }
    }
    for(int i = 0; i < n / 2; i++) {
      for(int j = 0; j < n; j++) {
	swap(mat[i][j], mat[n-1-i][j]);
      }
    }
  } else {
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	swap(mat[i][j], mat[j][i]);
      }
    }
    for(int i = 0; i < n / 2; i++) {
      for(int j = 0; j < n; j++) {
	swap(mat[i][j], mat[n-1-i][j]);
      }
    }
  }
}

void sym(bool rev) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n / 2; j++) {
      swap(mat[i][j], mat[i][n-1-j]);
    }
  }
}

void bhsym(bool rev) {
  for(int i = n/2; i < n; i++) {
    for(int j = 0; j < n/2; j++) {
      swap(mat[i][j], mat[i][n-1-j]);
    }
  }
}

void bvsym(bool rev) {
  for(int i = n/2; i < 3 * n / 4; i++) {
    for(int j = 0; j < n; j++) {
      swap(mat[i][j], mat[n-1-(i-n/2)][j]);
    }
  }
}

void div(bool rev) {
  memcpy(cpy, mat, sizeof mat);
  if(rev) {
    for(int i = 0; i < n; i+=2) {
      for(int j = 0; j < n; j++) {
	mat[i][j] = cpy[i/2][j];
      }
    }
    for(int i = 1; i < n; i+=2) {
      for(int j = 0; j < n; j++) {
	mat[i][j] = cpy[i/2+n/2][j];
      }
    }
  } else {
    for(int i = 0; i < n/2; i++) {
      for(int j = 0; j < n; j++) {
	mat[i][j] = cpy[i*2][j];
      }
    }
    for(int i = n/2; i < n; i++) {
      for(int j = 0; j < n; j++) {
	mat[i][j] = cpy[(i-n/2)*2+1][j];
      }
    }
  }
}

void mix(bool rev) {
  memcpy(cpy, mat, sizeof mat);
  if(rev) {
    for(int i = 0; i < n; i+=2) {
      for(int j = 0; j < n; j++) {
	if(j < n / 2) {
	  mat[i][j] = cpy[i][j*2];
	} else {
	  mat[i][j] = cpy[i+1][(j-n/2)*2];
	}
      }
      for(int j = 0; j < n; j++) {
	if(j < n / 2) {
	  mat[i+1][j] = cpy[i][j*2+1];
	} else {
	  mat[i+1][j] = cpy[i+1][(j-n/2)*2+1];
	}
      }
    }
  } else {
    for(int i = 0; i < n; i+=2) {
      for(int j = 0; j < n; j++) {
	if(j % 2) {
	  mat[i][j] = cpy[i+1][j/2];
	} else {
	  mat[i][j] = cpy[i][j/2];
	}
      }
      for(int j = 0; j < n; j++) {
	if(j % 2) {
	  mat[i+1][j] = cpy[i+1][j/2+n/2];
	} else {
	  mat[i+1][j] = cpy[i][j/2+n/2];
	}
      }
    }
  }
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * (b / gcd(a, b));
}

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n >> ws;
    init();
    string line;
    getline(cin, line);
    stringstream ss(line.c_str());
    string word;
    stack<string> st;
    while(ss >> word) {
      st.push(word);
    }
    while(!st.empty()) {
      word = st.top();
      st.pop();
      bool rev = false;
      if(word[word.length() - 1] == '-') {
	rev = true;
	word = word.substr(0, word.length() - 1);
      }
      if(word == "id") {
	id(rev);
      } else if(word == "rot") {
	rot(rev);
      } else if(word == "sym") {
	sym(rev);
      } else if(word == "bhsym") {
	bhsym(rev);
      } else if(word == "bvsym") {
	bvsym(rev);
      } else if(word == "div") {
	div(rev);
      } else if(word == "mix") {
	mix(rev);
      }
    }
    // for(int i = 0; i < n; i++) {
    //   for(int j = 0; j < n; j++) {
    // 	cout << mat[i][j].first << "," << mat[i][j].second << " ";
    //   }
    //   cout << endl;
    // }
    memset(visited, false, sizeof visited);
    int ans = 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	if(!visited[i][j]) {
	  int cnt = 0;
	  int ii = i, jj = j;
	  while(!visited[ii][jj]) {
	    visited[ii][jj] = true;
	    Point next = mat[ii][jj];
	    ii = next.first;
	    jj = next.second;
	    cnt++;
	  }
	  ans = lcm(ans, cnt);
	}
      }
    }
    cout << ans << endl;
    if(tc)
      cout << endl;
  }
  return 0;
}
