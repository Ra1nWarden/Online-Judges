#include <iostream>
#include <set>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

set<int> adjList[26];
int dfs_num[26];
bool recStack[26];
vector<int> toposorted;
int degree[26];

void topoVisit(int u) {
  dfs_num[u] = 1;
  for(set<int>::iterator itr = adjList[u].begin(); itr != adjList[u].end(); itr++) {
    int i = *itr;
    if(dfs_num[i] == 0)
      topoVisit(i);
  }
  toposorted.push_back(u);
}

bool isCyclicUtil(int v) {
  if(dfs_num[v] == 0) {
    dfs_num[v] = 1;
    recStack[v] = true;
    
    for(set<int>::iterator itr = adjList[v].begin(); itr != adjList[v].end(); itr++) {
      if(dfs_num[*itr] == 0 && isCyclicUtil(*itr))
	return true;
      else if (recStack[*itr])
	return true;
    }
  }
  recStack[v] = false;
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  string line;
  getline(cin, line);
  for(int i = 0; i < n; i++) {
    getline(cin, v[i]);
  }
  memset(degree, 0, sizeof degree);
  for(int i = 0; i < n-1; i++) {
    string a = v[i];
    string b = v[i+1];
    for(int j = 0; j < a.length(); j++) {
      if(j >= b.length()) {
	cout << "Impossible" << endl;
	return 0;
      }
      if(a[j] != b[j]) {
	// a[j] < b[j]
	char smaller = a[j];
	char larger = b[j];
	//cout << "smaller is " << smaller << " larger is " << larger << endl;
	adjList[smaller - 'a'].insert(larger - 'a');
	degree[larger - 'a']++;
	break;
      }
    }
  }

  // check cycle first
  memset(dfs_num, 0, sizeof dfs_num);
  memset(recStack, false, sizeof recStack);

  for(int i = 0; i < 26; i++) {
    if(isCyclicUtil(i)) {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  toposorted.clear();
  memset(dfs_num, 0, sizeof dfs_num);
  for(int i = 0; i < 26; i++) {
    if(degree[i] == 0 && dfs_num[i] == 0)
      topoVisit(i);
  }
  for(int i = toposorted.size() - 1; i >= 0; i--)
    cout << (char) ('a' + toposorted[i]);
  cout << endl;
  return 0;
}
