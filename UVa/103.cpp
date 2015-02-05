#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

bool contain[31][31];
map<int, vector<int> > memo;

struct Node {
  Node(vector<int>& raw) {
    sort(raw.begin(), raw.end());
    dimension = raw;
  };
  vector<int> dimension;
  bool contain(const Node& another) {
    for(int i = 0; i < dimension.size(); i++) {
      if(another.dimension[i] >= dimension[i])
	return false;
    }
    return true;
  };
};

void init(vector<Node>& nodes) {
  for(int i = 0; i < nodes.size(); i++) {
    for(int j = 0; j < nodes.size(); j++) {
      if(i == j) {
	contain[i][j] = false;
	continue;
      }
      contain[i][j] = nodes[i].contain(nodes[j]);
    }
  }
  memo.clear();
}

vector<int> findMax(const vector<Node>& nodes, int index) {
  if(memo.count(index) != 0)
    return memo[index];
  vector<int> result;
  for(int i = 0; i < nodes.size(); i++) {
    if(i == index)
      continue;
    if(contain[index][i]) {
      vector<int> subresult = findMax(nodes, i);
      subresult.push_back(index);
      if(subresult.size() > result.size())
	result = subresult;
    }
  }
  if(result.size() == 0) {
    result.push_back(index);
  }
  memo[index] = result;
  return result;
}

int main() {
  int m, n;
  while(cin >> m >> n) {
    memset(contain, false, sizeof contain);
    vector<Node> nodes;
    for(int i= 0; i < m; i++) {
      int x;
      vector<int> sides;
      for(int j = 0; j < n; j++) {
	cin >> x;
	sides.push_back(x);
      }
      Node each(sides);
      nodes.push_back(each);
    }
    init(nodes);
    vector<int> result;
    for(int i = 0; i < nodes.size(); i++) {
      vector<int> nextResult = findMax(nodes, i);
      if(nextResult.size() > result.size()) {
	result = nextResult;
      }
    }
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) {
      if(i != result.size() - 1)
	cout << result[i] + 1 << " ";
      else
	cout << result[i] + 1 << endl;
    }
  }
  return 0;
}
