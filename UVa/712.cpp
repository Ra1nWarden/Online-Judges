#include <iostream>
#include <sstream>
#include <cstring>
#define MAXN 10

using namespace std;

int n;

int m[MAXN];
bool tree[1024];

int main() {
  ios::sync_with_stdio(false);
  int kase = 1;
  string line;
  while(cin >> n && n) {
    getline(cin, line);
    getline(cin, line);
    stringstream ss(line.c_str());
    for(int i = 0; i < n; i++) {
      string word;
      ss >> word;
      m[i] = word[1] - '1';
    }

    getline(cin, line);
    memset(tree, false, sizeof tree);
    for(int i = 0; i < (1 << n); i++) {
      tree[(1 << n) + i] = line[i] == '1';
    }
    int q;
    cin >> q;
    cout << "S-Tree #" << kase++ << ":" << endl;
    getline(cin, line);
    for(int i = 0; i < q; i++) {
      getline(cin, line);
      int pos = 1;
      for(int j = 0; j < n; j++) {
	if(line[m[j]] == '1') {
	  //cout << "right" << endl;
	  pos = ((pos << 1) | 1);
	} else {
	  //cout << "left" << endl;
	  pos = (pos << 1);
	}
	//cout << "pos at " << pos << endl;
      }
      cout << tree[pos];
    }
    cout << endl;
    cout << endl;
  }
  return 0;
}
