#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;

map<char, vector<char> > edges;
set<char> visited;
vector<char> chars;

void generate(string prefix) {
  if(prefix.length() == chars.size()) {
    cout << prefix << endl;
  }
  else {
    for(int i= 0; i < chars.size(); i++) {
      if(visited.count(chars[i]) == 0) {
	bool valid = true;
	for(int j= 0; j < edges[chars[i]].size(); j++) {
	  if(visited.count(edges[chars[i]][j]) == 0) {
 	    valid = false;
	    break;
	  }
	}
	if(valid) {
	  visited.insert(chars[i]);
	  generate(prefix + chars[i]);
	  visited.erase(chars[i]);
	}
      }
    }
  }
}

int main() {
  string line;
  bool first = true;
  while(getline(cin, line)) {
    if(!first)
      cout << endl;
    chars.clear();
    char each;
    istringstream iss(line.c_str());
    while(iss >> each) {
      chars.push_back(each);
    }
    sort(chars.begin(), chars.end());
    getline(cin, line);
    istringstream iss2(line.c_str());
    char start, end;
    edges.clear();
    while(iss2 >> start >> end) {
      if(edges.count(end) == 0) {
	vector<char> singleton;
	singleton.push_back(start);
	edges[end] = singleton;
      }  else {
	edges[end].push_back(start);
      }
    }
    visited.clear();
    
    generate("");
    first = false;
  }
  return 0;
}
