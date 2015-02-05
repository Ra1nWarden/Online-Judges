#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <sstream>

using namespace std;

bool edges[30][30];
map<string, int> indexMap;
int bfsdepth[30];
int n;

int bfs(int start, int end) {
  bfsdepth[start] = 0;
  queue<int> q;
  q.push(start);
  while(bfsdepth[end] == -1 && !q.empty()) {
    int next = q.front();
    q.pop();
    for(int i= 0; i < n; i++) {
      if(edges[next][i] && bfsdepth[i] == -1) {
	bfsdepth[i] = bfsdepth[next] + 1;
	q.push(i);
      }
    }
  }
  return bfsdepth[end];
}

int main() {
  int tc;
  cin >> tc;
  cout << "SHIPPING ROUTES OUTPUT" << endl;
  cout << endl;
  for(int t = 1; t <= tc; t++) {
    cout << "DATA SET  " << t << endl;
    cout << endl;
    int e, q;
    cin >> n >> e >> q;
    string line;
    getline(cin, line);
    getline(cin, line);
    string node;
    istringstream iss(line.c_str());
    int nodeIndex = 0;
    while(getline(iss, node, ' ')) {
      indexMap[node] = nodeIndex++;
    }
    memset(edges, false, sizeof edges);
    for(int i = 0; i < e; i++) {
      getline(cin, line);
      istringstream iss2(line.c_str());
      string side1, side2;
      getline(iss2, side1, ' ');
      getline(iss2, side2);
      int side1n = indexMap[side1];
      int side2n = indexMap[side2];
      edges[side1n][side2n] = true;
      edges[side2n][side1n] = true;
    }
    for(int i= 0; i < q; i++) {
      getline(cin, line);
      string start, end;
      int ship;
      istringstream iss3(line.c_str());
      iss3 >> ship >> ws;
      getline(iss3, start, ' ');
      getline(iss3, end);
      memset(bfsdepth, -1, sizeof bfsdepth);
      int length = bfs(indexMap[start], indexMap[end]);
      if(length == -1) {
	cout << "NO SHIPMENT POSSIBLE" << endl;
      }
      else {
	cout << "$" << length * 100 * ship << endl;
      }
    }
    cout << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
