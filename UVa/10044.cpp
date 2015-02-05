#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct Node {
  Node() {};
  Node(string s, vector<string> v) : index(s), adj(v), degree(-1) {};
  int degree;
  string index;
  vector<string> adj;
};

map<string, Node> nodes;
set<string> visited;

void bfs(string source) {
  visited.insert(source);
  nodes[source].degree = 0;
  queue<string> q;
  q.push(source);
  while(!q.empty()) {
    string next = q.front();
    q.pop();
    vector<string> nextadj = nodes[next].adj;
    for(int i= 0; i < nextadj.size(); i++) {
      if(visited.count(nextadj[i]) == 0) {
	// cout << "writing " << nextadj[i] << " degree" << endl;
	nodes[nextadj[i]].degree = nodes[next].degree+1;
	visited.insert(nextadj[i]);
	q.push(nextadj[i]);
      }
    }
  }
}

int main() {
  int cases;
  cin >> cases;
  for(int test = 1; test <= cases; test++) {
    int edge, query;
    cin >> edge >> query >> ws;
    nodes.clear();
    for(int i= 0; i < edge; i++) {
      string authors, title;
      getline(cin, authors, ':');
      getline(cin, title);
      vector<string> splitted;
      istringstream iss(authors.c_str());
      string split;
      bool firstone = true;
      while(getline(iss, split, ',')) {
	if(firstone)
	  splitted.push_back(split);
	else
	  splitted.push_back(split.substr(1));
	firstone = false;
      }
      vector<string> names;
      for(int j = 0; j < splitted.size() - 1; j +=2) {
	names.push_back(splitted[j] + ", " + splitted[j+1]);
      }
      for(int j= 0; j < names.size(); j++) {
	for(int k = j+1; k < names.size(); k++) {
	  string side1 = names[j];
	  string side2 = names[k];
	  if(nodes.count(side1) == 0) {
	    vector<string> side1adj;
	    side1adj.push_back(side2);
	    Node each(side1, side1adj);
	    nodes[side1] = each;
	  } else {
	    nodes[side1].adj.push_back(side2);
	  }

	  if(nodes.count(side2) == 0) {
	    vector<string> side2adj;
	    side2adj.push_back(side1);
	    Node each(side2, side2adj);
	    nodes[side2] = each;
	  } else {
	    nodes[side2].adj.push_back(side1);
	  }
	}
      }
    }
    bfs("Erdos, P.");
    visited.clear();
    cout << "Scenario " << test << endl;
    for(int i = 0; i < query; i++) {
      string querys;
      getline(cin, querys);
      if(nodes.count(querys) == 0 || nodes[querys].degree == -1)
	cout << querys << " infinity" << endl;
      else
	cout << querys << " " << nodes[querys].degree << endl;
    }
  }
  return 0;
}
