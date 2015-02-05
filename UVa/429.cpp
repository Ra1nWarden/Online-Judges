#include <iostream>
#include <sstream>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

bool edge[200][200];
int bfsIndex[200];
map<string, int> nodeIndex;

int bfs(int start, int end) {
  bfsIndex[start] = 0;
  queue<int> q;
  q.push(start);
  while(!q.empty() && bfsIndex[end] == -1) {
    int next = q.front();
    q.pop();
    for(int i = 0; i < nodeIndex.size(); i++) {
      if(edge[next][i] && bfsIndex[i] == -1) {
	bfsIndex[i] = bfsIndex[next]+1;
	q.push(i);
      }
    }
  }
  return bfsIndex[end];
}

int main() {
  int cases;
  cin >> cases;
  string line;
  getline(cin, line);
  getline(cin, line);
  bool start = true;
  while(cases--) {
    if(!start)
      cout << endl;
    vector<string> dict;
    int indexCount = 0;
    memset(edge, false, sizeof edge);
    while(getline(cin, line)) {
      if(line == "*")
	break;
      nodeIndex[line] = indexCount++;
      for(int i= 0; i < dict.size(); i++) {
	if(dict[i].length() == line.length()) {
	  int diff =0;
	  for(int j= 0; j < line.length(); j++) {
	    if(line[j] != dict[i][j])
	      diff++;
	  }
	  if(diff == 1) {
	    edge[nodeIndex[dict[i]]][nodeIndex[line]] = 1;
	    edge[nodeIndex[line]][nodeIndex[dict[i]]] = 1;
	  }
	}
      }
      dict.push_back(line);
    }
    while(getline(cin, line)) {
      if(line.empty())
	break;
      istringstream iss(line.c_str());
      string start, end;
      getline(iss, start, ' ');
      getline(iss, end);
      memset(bfsIndex, -1, sizeof bfsIndex);
      int result = bfs(nodeIndex[start], nodeIndex[end]);
      cout << start << " " << end << " " << result << endl;
    }
    start = false;
  }
  return 0;
}
