#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Node {
  Node() {};
  Node(string s, vector<string> t) : index(s), adj(t) {};
  string index;
  vector<string> adj;
  vector<string> seq;
};

map<string, Node> nodes;
set<string> visited;

void bfs(string start, string end) {
  visited.insert(start);
  vector<string> series;
  series.push_back(start);
  nodes[start].seq = series;
  queue<string> q;
  q.push(start);
  while(!q.empty() && visited.count(end) == 0) {
    string next = q.front();
    // cout << "next is " << next << endl;
    q.pop();
    vector<string> nextadj = nodes[next].adj;
    for(int i= 0; i < nextadj.size(); i++) {
      if(visited.count(nextadj[i]) == 0) {
	vector<string> newseq = nodes[next].seq;
	newseq.push_back(nextadj[i]);
	nodes[nextadj[i]].seq = newseq;
	visited.insert(nextadj[i]);
	q.push(nextadj[i]);
      }
    }
  }
} 

int main() {
  int cases;
  cin >> cases;
  bool start = true;
  while(cases--) {
    if(!start)
      cout << endl;
    int edge, query;
    cin >> edge >> query >> ws;
    nodes.clear();
    for(int i= 0; i < edge; i++) {
      string side1, side2;
      getline(cin, side1, ' ');
      getline(cin, side2);
      // cout << "side1 is  " << side1 << "  side2 is " << side2 << endl;
      if(nodes.count(side1) == 0) {
	vector<string> connect;
	connect.push_back(side2);
	Node each(side1, connect);
	nodes[side1] = each;
      } else {
	nodes[side1].adj.push_back(side2);
      }

      if(nodes.count(side2) == 0) {
	vector<string> connect;
	connect.push_back(side1);
	Node each(side2, connect);
	nodes[side2] = each;
      } else {
	nodes[side2].adj.push_back(side1);
      }      
    }
    for(int i= 0; i < query; i++) {
      string start, end;
      getline(cin, start, ' ');
      getline(cin, end);
      visited.clear();
      bfs(start, end);
      vector<string> result = nodes[end].seq;
      for(int j= 0; j < result.size(); j++) {
	cout << result[j][0];
      }
      cout << endl;
    }
    start = false;
  }
  return 0;
}
