#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  int v[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  //cout << "done" << endl;
  string line;
  getline(cin, line);
  vector<string> m(n);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    //cout << "read line " << line << endl;
    m[i] = line;
  }
  bool visited[n];
  memset(visited, false, sizeof visited);
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      stack<int> s;
      s.push(i);
      visited[i] = true;
      vector<int> nextv;
      nextv.push_back(v[i]);
      vector<int> nexti;
      nexti.push_back(i);
      while(!s.empty()) {
	int next = s.top();
	s.pop();
	for(int j = 0; j < n; j++) {
	  if(m[next][j] == '1' && !visited[j]) {
	    s.push(j);
	    visited[j] = true;
	    nextv.push_back(v[j]);
	    nexti.push_back(j);
	  }
	}
      }
      if(nextv.size() > 1) {
	sort(nextv.begin(), nextv.end());
	sort(nexti.begin(), nexti.end());
	for(int j = 0; j < nexti.size(); j++)
	  v[nexti[j]] = nextv[j];
      }
    }
  }
  for(int i= 0; i < n; i++) {
    if(i != 0)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
