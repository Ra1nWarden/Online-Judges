#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <cstring>
#include <queue>
#include <cstdlib>

using namespace std;

struct Node {
  Node() {};
  Node(int n, vector<int> a) : index(n), adj(a) {};
  int index;
  vector<int> seq;
  vector<int> adj;
};

map<int, Node> nodes;
bool visited[301];

void bfs(int start, int end) {
  visited[start] = true;
  nodes[start].seq.clear();
  nodes[start].seq.push_back(start);
  queue<int> q;
  q.push(start);
  while(!q.empty() && !visited[end]) {
    int nextn = q.front();
    q.pop();
    vector<int> newadj = nodes[nextn].adj;
    for(int i= 0; i < newadj.size(); i++) {
      if(!visited[newadj[i]]) {
	visited[newadj[i]] = true;
	vector<int> newseq = nodes[nextn].seq;
	newseq.push_back(newadj[i]);
	nodes[newadj[i]].seq = newseq;
	q.push(newadj[i]);
      }
    }
  }
}

int main() {
  int n;
  while(cin >> n >> ws) {
    string line;
    nodes.clear();
    for(int i= 0; i < n; i++) {
      getline(cin, line);
      string starts;
      istringstream iss(line.c_str());
      getline(iss, starts, '-');
      int startn = atoi(starts.c_str());
      string ends;
      vector<int> connections;
      while(getline(iss, ends, ',')) {
	int endn = atoi(ends.c_str());
	connections.push_back(endn);
      }
      Node node(startn, connections);
      nodes[startn] = node;
    }
    int q;
    cin >> q;
    cout << "-----" << endl;
    for(int i= 0; i < q; i++) {
      int start, end;
      memset(visited, false, sizeof visited);
      cin >> start >> end;
      bfs(start, end);
      if(visited[end]) {
	vector<int> sequence = nodes[end].seq;
	for(int i= 0; i < sequence.size(); i++) {
	  if(i == 0)
	    cout << sequence[i];
	  else
	    cout << " " << sequence[i];
	}
      } else {
	cout << "connection impossible";
      }
      cout << endl;
    }
  }
  return 0;
}
