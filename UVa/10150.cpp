#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int ignoreIndex = -1;

struct Node {
  Node() {};
  Node(string s) : index(s) {};
  string index;
  vector<string> seq;
};

struct Indexsort {
  Indexsort(int n) : ignore(n) {};
  int ignore;
  bool operator() (string a, string b) {
    if(a.length() != b.length())
      return a.length() < b.length();
    if(ignore > a.length() - 1)
      return a < b;
    else {
      string converta = a;
      string convertb = b;
      converta[ignore] = ' ';
      convertb[ignore] = ' ';
      
      return converta < convertb;
    }
  };
};

set<string> visited;
vector<string> nodes;
vector<string> path;
vector<vector<string> > sortednodes;

void bfs(string start, string end) {
  visited.insert(start);
  queue<Node> q;
  Node each(start);
  each.seq.push_back(start);
  q.push(each);
  while(!q.empty() && visited.count(end) == 0) {
    Node next = q.front();
    q.pop();
    string nexts = next.index;
    vector<string> qadj;
    for(int i = 0; i < nexts.length(); i++) {
      Indexsort sortcomp(i);
      // cout << "sorted range" << endl;
      // for(int j = 0; j < nodes.size(); j ++)
      // 	cout << nodes[j] << " ";
      // cout << endl;
      pair<vector<string>::iterator, vector<string>::iterator> equalrange = equal_range(sortednodes[i].begin(), sortednodes[i].end(), nexts, sortcomp);
      //cout << "for word " << nexts << endl;
      //cout << "range is "  << equalrange.first - nodes.begin() << " to " << equalrange.second - nodes.begin() << endl;
      for(vector<string>::iterator itr = equalrange.first; itr != equalrange.second; itr++) {
	// cout << nexts << " is adjacent to " << *itr << endl; 
	qadj.push_back(*itr);
      }
    }
    for(int i = 0; i < qadj.size(); i++) {
      if(visited.count(qadj[i]) == 0) {
	visited.insert(qadj[i]);
	Node newnode(qadj[i]);
	newnode.seq = next.seq;
	newnode.seq.push_back(qadj[i]);
	q.push(newnode);
	if(qadj[i] == end) {
	  path = newnode.seq;
	}
      }
    }
  }
}

int main() {
  string line;
  nodes.clear();
  while(getline(cin, line)) {
    if(line.empty())
      break;
    nodes.push_back(line);
  }

  for(int i= 0; i < 16; i++) {
    Indexsort sortcomp(i);
    sort(nodes.begin(), nodes.end(), sortcomp);
    sortednodes.push_back(nodes);
  }
  
  string start, end;
  bool startEndl = true;
  while(getline(cin, start, ' ')) {
    getline(cin, end);
    visited.clear();
    path.clear();
    if(!startEndl)
      cout << endl;
    bfs(start, end);
    if(visited.count(end) == 0) {
      cout << "No solution." << endl;
    } else {
      for(int i = 0; i < path.size(); i++)
	cout << path[i] << endl;
    }
    startEndl = false;
  }
  
  return 0;
}
