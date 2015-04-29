#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 2000000000

using namespace std;

typedef pair<int, long long> Node;
typedef vector<Node>::iterator NITR;

bool _cmp(const Node& a, const Node& b) {
  if(a.first > b.first) {
    return (a.second << (a.first - b.first)) < b.second;
  } else if(a.first < b.first) {
    return a.second < (b.second << (b.first - a.first)); 
  } else {
    return a.second < b.second;
  }
}

int main() {
  int tc;
  cin >> tc;
  string line;
  getline(cin, line);
  for(int i = 0; i < tc; i++) {
    vector<Node> nodes;
    getline(cin, line);
    //cout << "read line " << line << endl;
    int level = 1;
    for(int j = 0; j < line.length(); j++) {
      if(line[j] == '[') {
	level++;
      } else if(line[j] == ']') {
	level--;
      } else if(line[j] >= '0' && line[j] <= '9') {
	int len = 1;
	for(int k = j + 1; k < line.length(); k++) {
	  if(line[k] >= '0' && line[k] <= '9') {
	    len++;
	  } else {
	    break;
	  }
	}
	long long number = (long long) atoi(line.substr(j, len).c_str());
	j += (len - 1);
	//cout << "making pair " << "(" << level << ", " << number << ")" << endl;
	nodes.push_back(make_pair(level, number));
      }
    }
    sort(nodes.begin(), nodes.end(), _cmp);
    int maxVal = 0;
    vector<Node>::iterator itr = nodes.begin();
    while(itr != nodes.end()) {
      pair<NITR, NITR> bounds = equal_range(nodes.begin(), nodes.end(), *itr, _cmp);
      maxVal = max(maxVal, (int) (bounds.second - bounds.first));
      //cout << "each segment is " << (int) (bounds.second - bounds.first) << endl;
      itr = bounds.second;
    }
    cout << (nodes.size() - maxVal) << endl;
  }
  return 0;
}
