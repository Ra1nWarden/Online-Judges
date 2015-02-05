#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Node {
  Node(int n) : number(n) {
    sequence.push_back(n);
  };
  int number;
  vector<int> sequence;
  bool operator<(const Node& another) const {
    return number < another.number;
  };
  bool operator<=(const Node& another) const {
    return number < another.number || number == another.number;
  };
};

int main() {
  int cases;
  cin >> cases >> ws;
  string line;
  bool start = true;
  while(cases--) {
    if(!start)
      cout << endl;
    vector<Node> nodes;
    while(getline(cin, line) && line.length() != 0) {
      int number = atoi(line.c_str());
      Node each(number);
      if(nodes.empty()) {
	nodes.push_back(each);
      }
      else if(each <= nodes[0]) {
	nodes[0] = each;
      } 
      else if(nodes.back() < each) {
	vector<int> newsequence = nodes.back().sequence;
	newsequence.push_back(each.number);
	each.sequence = newsequence;
	nodes.push_back(each);
      }
      else {
	vector<Node>::iterator itr = lower_bound(nodes.begin(), nodes.end(), each);
	Node prev = *(itr -1);
	vector<int> newsequence = prev.sequence;
	newsequence.push_back(each.number);
	itr->number = each.number;
	itr->sequence = newsequence;
      }
    }
    if(nodes.size() != 0) {
      printf("Max hits: %lu\n", nodes.back().sequence.size());
      for(int i= 0; i < nodes.back().sequence.size(); i++)
	cout << nodes.back().sequence[i] << endl;
    } else {
      printf("Max hits: 0\n");
    }
    start = false;
  }
  return 0;
}
