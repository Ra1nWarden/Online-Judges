#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  Node() {};
  Node(string s, vector<string> c) : index(s), adj(c) {};
  string index;
  vector<string> adj;
  vector<string> seq;
};

map<string, Node> nodes;
set<string> visited;

void bfs(string start, string end) {
  visited.insert(start);
  nodes[start].seq.clear();
  nodes[start].seq.push_back(start);
  queue<string> q;
  q.push(start);
  while(!q.empty() && visited.count(end) == 0) {
    string next = q.front();
    q.pop();
    vector<string> adjacent = nodes[next].adj;
    for(int i= 0; i < adjacent.size(); i++) {
      if(visited.count(adjacent[i]) == 0) {
	visited.insert(adjacent[i]);
	vector<string> newseq = nodes[next].seq;
	newseq.push_back(adjacent[i]);
	nodes[adjacent[i]].seq = newseq;
	q.push(adjacent[i]);
      }
    }
  }
}

int main() {
  int n;
  bool startEndl = true;
  while(cin >> n >> ws) {
    if(!startEndl)
      cout << endl;
    nodes.clear();
    visited.clear();
    for(int i= 0; i < n; i++) {
      string start, end;
      getline(cin, start, ' ');
      getline(cin, end);
      if(nodes.count(start) == 0) {
	vector<string> edge;
	edge.push_back(end);
	Node each(start, edge);
	nodes[start] = each;
      } else {
	nodes[start].adj.push_back(end);
      }
      
      if(nodes.count(end) == 0) {
	vector<string> edge;
	edge.push_back(start);
	Node each(end, edge);
	nodes[end] = each;
      } else {
	nodes[end].adj.push_back(start);
      }
    }
    string start, end;
    getline(cin, start, ' ');
    getline(cin, end);
    bfs(start, end);
    if(visited.count(end) == 0)
      cout << "No route" << endl;
    else {
      vector<string> sequence = nodes[end].seq;
      for(int i= 0; i < sequence.size() - 1; i++) {
	cout << sequence[i] << " " << sequence[i+1] << endl;
      }
    }
    startEndl = false;
  }
  return 0;
}
