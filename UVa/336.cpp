#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Node {
  Node(int number) : index(number) {};
  int index;
  vector<int> connections;
};

int findReachable(int start, int ttl, map<int, Node*> nodes) {
  int total = nodes.size();
  set<int> visited;
  queue<int> waitlist;
  waitlist.push(start);
  visited.insert(start);
  for(int i = 0; i < ttl; i++) {
    int queuesize = waitlist.size();
    for(int j = 0; j < queuesize; j++) {
      int current = waitlist.front();
      waitlist.pop();
      visited.insert(current);
      Node* currentNode = nodes[current];
      for(int k = 0; k < currentNode->connections.size(); k++) {
	int neighbor = currentNode->connections[k];
	if(visited.count(neighbor) == 0) {
	  visited.insert(neighbor);
	  waitlist.push(nodes[neighbor]->index);
	}
      }
    }
  }
  return nodes.size() - visited.size();
}

int main() {
  int cases = 1;
  while(true) {
    int links;
    cin >> links;
    if(links == 0)
      break;
    map<int, Node*> nodes;
    for(int i = 0; i < links; i++) {
      int a, b;
      cin >> a >> b;
      if(nodes.count(a) == 0) {
	Node* newnode = new Node(a);
	nodes[a] = newnode;
      }
      if(nodes.count(b) == 0) {
	Node* newnode = new Node(b);
	nodes[b] = newnode;
      }
      Node* first = nodes[a];
      Node* second = nodes[b];
      first->connections.push_back(b);
      second->connections.push_back(a);
    }
    while(true) {
      int start, ttl;
      cin >> start >> ttl;
      if (start == 0 && ttl == 0)
	break;
      int result = findReachable(start, ttl, nodes);
      cout << "Case " << cases << ": " << result << " nodes not reachable from node " << start << " with TTL = " << ttl << ".\n";
      cases++;
    }
  }
  return 0;
}
