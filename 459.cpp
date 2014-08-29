#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct Node {
  char value;
  char parent;
  Node(char c) : value(c), parent(c) {};
};

char findSet(vector<Node>& nodes, char a) {
  char result = nodes[a - 'A'].value;
  while (nodes[result - 'A'].parent != result) {
    result = nodes[result - 'A'].parent;
  }
  return result;
}

void combine(char one, char two, vector<Node>& nodes) {
  Node& secondRep = nodes[findSet(nodes, two) - 'A'];
  Node& oneRep = nodes[findSet(nodes, one) - 'A'];
  oneRep.parent = secondRep.value;
}

void pathCompression(vector<Node>& nodes) {
  while(true) {
    bool swapped = false;
    for (int i = 0; i < nodes.size(); i++) {
      Node& current = nodes[i];
      Node& parent = nodes[current.parent - 'A'];
      if (current.parent != parent.parent) {
	current.parent = parent.parent;
	swapped = true;
	break;
      }
    }
    if (!swapped)
      break;
  }
}

int countSet(vector<Node>& nodes) {
  pathCompression(nodes);
  set<char> sets;
  for (int i = 0; i < nodes.size(); i++) {
    sets.insert(nodes[i].parent);
  }
  return sets.size();
}

int main() {
  int cases;
  cin >> cases >> ws;
  string line;
  for (int i = 0; i < cases; i++) {
    if (i != 0)
      cout << endl;
    getline(cin, line);
    char max = line[0];
    vector<Node> nodes;
    for (char c = 'A'; c <= max; c++) {
      nodes.push_back(Node(c));
    }
    while(getline(cin, line)) {
      if (line == "")
	break;
      char one = line[0];
      char two = line[1];
      combine(one, two, nodes);
    }
    cout << countSet(nodes) << endl;
  }
  return 0;
}
