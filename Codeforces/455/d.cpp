#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

const int maxn = 1000000;
char str[maxn+5];

typedef pair<char, int> Node;

void try_insert(vector<Node>& nodes, Node new_node) {
  if(nodes.empty()) {
    nodes.push_back(new_node);
  } else if(nodes.back().first == new_node.first) {
    nodes.back().second += new_node.second;
  } else {
    nodes.push_back(new_node);
  }
}

vector<Node> merge(const vector<Node>& nodes) {
  vector<Node> new_nodes;
  for(int i = 0; i < nodes.size(); i++) {
    if(nodes[i].second == 1) {
      continue;
    } else if(i == 0 || i == nodes.size() - 1) {
      Node new_node = nodes[i];
      new_node.second--;
      try_insert(new_nodes, new_node);
    } else {
      Node new_node = nodes[i];
      if(new_node.second > 2) {
	new_node.second -= 2;
	try_insert(new_nodes, new_node);
      }
    }
  }
  return new_nodes;
}

int main() {
  scanf("%s", str);
  char prev = '\0';
  int len = 0;
  vector<Node> nodes;
  for(int i = 0; i >= 0; i++) {
    if(str[i] == '\0') {
      nodes.push_back(make_pair(prev, len));
      break;
    }
    if(str[i] != prev) {
      if(prev != '\0') {
	nodes.push_back(make_pair(prev, len));
      }
      prev = str[i];
      len = 1;
    } else {
      len++;
    }
  }
  int ans = 0;
  while(nodes.size() > 1) {
    nodes = merge(nodes);
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
