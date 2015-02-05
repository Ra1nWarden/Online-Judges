#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

bool DEBUG = true;

struct Node {
  vector<char> chars;
  bool operator<(const Node& another) const {
    return chars.front() < another.chars.front();
  };
};

int v[26][26];
int dfsnum[26];
int dfslow[26];
vector<Node> nodes;
stack<int> dfs_scc;
set<int> in_stack;
int dfsCount;
int n;

void tarjan(int u) {
  dfsnum[u] = dfslow[u] = dfsCount++;
  dfs_scc.push(u);
  in_stack.insert(u);
  for(int i= 0; i < 26; i++) {
    // if(u == 'C' -'A') {
    //   cout << "u is C, i is " << i << " waiting for " << v['C'-'A']['E' - 'A'] << endl;;
    // }
    if(v[u][i] == 1) {
      // cout << "from " << (char)('A' + u) << " to " << (char)(i + 'A') << endl;
      if(dfsnum[i] == -1) {
	// cout << "if: "<< (char)(i+'A') << " not visited" << endl; 
	tarjan(i);
	// cout << "if min of " << dfslow[u] << ", " << dfslow[i] << endl;
	dfslow[u] = min(dfslow[u], dfslow[i]);
      }
      else if(in_stack.count(i) != 0) {
	// cout << "else: " << endl;
	// cout << "else if min of " << dfslow[u] << ", " << dfsnum[i] << endl;
	dfslow[u] = min(dfslow[u], dfsnum[i]);
      }
    }
    // cout << "loop end for i == " << i << " n is " << n << endl; 
  }
  if(dfslow[u] == dfsnum[u]) {
    Node node;
    while(!dfs_scc.empty() && dfs_scc.top() != u) {
      int next = dfs_scc.top();
      dfs_scc.pop();
      in_stack.erase(next);
      node.chars.push_back(next + 'A');
    }
    // cout << "finishing with " << (char)(u + 'A') << endl;
    dfs_scc.pop();
    in_stack.erase(u);
    node.chars.push_back(u + 'A');
    sort(node.chars.begin(), node.chars.end());
    nodes.push_back(node);
  }
}

int main() {
  int tc = 0;
  while(cin >> n && n) {
    if(tc)
      cout << endl;
    string line;
    getline(cin, line);
    memset(v, 0, sizeof v);
    for(int i =0; i < 26; i++)
      dfsnum[i] = -2;
    for(int i= 0; i < n; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      char each;
      vector<char> chars;
      while(iss >> each)
	chars.push_back(each);
      dfsnum[chars.back() - 'A'] = -1;
      for(int i= 0; i < chars.size() -1; i++) {
	dfsnum[chars[i] - 'A'] = -1;
	if(chars[i] != chars.back()) {
	  // cout << "connecting " << chars.back() << " to " << chars[i] << endl;
	  // cout << "writing to index " << chars.back() - 'A' << " and " << chars[i] - 'A' << endl;
	  v[chars.back() - 'A'][chars[i] - 'A'] = 1;
	}
      }
    }

    // for(int i = 0; i < 26; i++) {
    //   for(int j =0; j < 26; j++) {
    // 	cout << "v" << i << ", " << j << ": " << (char)(i+'A') << ", " << (char)(j+'A') << " is " << v[i][j] << endl;
    //   }
    // }

    memset(dfslow, -1, sizeof dfslow);
    dfsCount = 0;
    while(!dfs_scc.empty())
      dfs_scc.pop();
    in_stack.clear();
    nodes.clear();
    for(int i = 0; i < 26; i++) {
      if(dfsnum[i] == -1) {
	// cout << "before function call " << i << endl;
	tarjan(i);
      }
    }
    sort(nodes.begin(), nodes.end());
    for(int i = 0; i < nodes.size(); i++) {
      for(int j = 0; j < nodes[i].chars.size(); j++) {
	if(j > 0)
	  cout << " " << nodes[i].chars[j];
	else
	  cout << nodes[i].chars[j];
      }
      cout << endl;
    }
    tc++;
  }
  return 0;
}
