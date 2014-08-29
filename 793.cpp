#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Node {
  int value;
  int parent;
  Node(int v) : value(v), parent(v) {};
};

int findSet(vector<Node>& nodes, int a) {
  int result = nodes[a - 1].value;
  while(nodes[result - 1].parent != result) {
    result = nodes[result - 1].parent;
  }
  return result;
}

void combine(int a, int b, vector<Node>& nodes) {
  Node& oneRep = nodes[findSet(nodes, a) - 1];
  Node& twoRep = nodes[findSet(nodes, b) - 1];
  oneRep.parent = twoRep.value;
}

void compressPath(vector<Node>& nodes) {
  for(int i = 0; i < nodes.size(); i++) {
    Node& current = nodes[i];
    Node* parent = &nodes[current.parent - 1];
    while (parent->parent != parent->value) {
      parent = &nodes[parent->parent - 1];
    }
    current.parent = parent->value;
  }
}

bool isSameSet(int a, int b, vector<Node>& nodes) {
  compressPath(nodes);
  return nodes[a - 1].parent == nodes[b - 1].parent;
}

int main() {
  int cases;
  cin >> cases;
  string line;
  getline(cin, line);
  for(int i = 0; i < cases; i++) {
    if (i != 0)
      cout << endl;
    int success = 0;
    int failure = 0;
    int total;
    cin >> total >> ws;
    vector<Node> nodes;
    for (int j = 1; j <= total; j++) {
      nodes.push_back(Node(j));
    }
    while(getline(cin, line)) {
      if (line == "")
	break;
      char method;
      int a, b;
      istringstream iss(line.c_str());
      iss >> method >> a >> b;
      if (method == 'c') {
        combine(a, b, nodes);
      }
      if (method == 'q') {
	if(isSameSet(a, b, nodes))
	  success++;
	else
	  failure++;
      }
    }
    cout << success << "," << failure << endl;
  }
  return 0;
}
