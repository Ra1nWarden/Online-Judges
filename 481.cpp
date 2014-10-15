#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool DEBUG = false;

struct Node {
  Node(int n) : number(n) {
    sequence.push_back(n);
  };
  int number;
  vector<int> sequence;
  bool operator<(const Node& another) const {
    return number < another.number;
  };
  bool operator==(const Node& another) const {
    return number == another.number;
  };
  bool operator<=(const Node& another) const {
    return (*this) < another || (*this) == another;
  };
};

int main() {
  int number;
  vector<Node> nodes;
  while(cin >> number) {
    if(DEBUG)
      cout << "buidling " << number << endl;
    Node each(number);
    if(nodes.empty()) {
      if(DEBUG)
	cout << "if" << endl;
      nodes.push_back(each);
    }
    else if(each <= nodes[0]) {
      if(DEBUG)
	cout << "else if" << endl;
      nodes[0] = each;
    }
    else if(nodes.back() < each){
      if(DEBUG)
	cout << "else if" << endl;
      vector<int> newsequence = nodes.back().sequence;
      newsequence.push_back(each.number);
      each.sequence = newsequence;
      nodes.push_back(each);
    } else {
      if(DEBUG)
	cout << "else" << endl;
      vector<Node>::iterator itr = lower_bound(nodes.begin(), nodes.end(), each);
      Node prev = *(itr-1);
      vector<int> newsequence = prev.sequence;
      newsequence.push_back(each.number);
      itr->number = each.number;
      itr->sequence = newsequence;
    }
    if(DEBUG) {
      cout << "printing nodes:" << endl;
      for(int i = 0; i < nodes.size(); i++) {
	cout << nodes[i].number << endl;
	for(int j= 0; j < nodes[i].sequence.size(); j++)
	  cout << nodes[i].sequence[j] << " ";
	cout << endl;
      }
    }
  }
  vector<int> longest = nodes.back().sequence;
  cout << longest.size() << endl;
  cout << "-" << endl;
  for(int i= 0; i < longest.size(); i++) {
    cout << longest[i] << endl;
  }
  return 0;
}
