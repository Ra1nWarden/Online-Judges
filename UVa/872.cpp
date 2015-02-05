#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<char> chars;
bool edges[26][26];
bool visited[26];
bool solution;

void generate(string prefix) {
  if(prefix.length() == chars.size()) {
    solution = true;
    for(int i = 0; i < prefix.length(); i++) {
      if(i != prefix.length() - 1)
	cout << prefix[i] << " ";
      else
	cout << prefix[i] << endl;
    }
  }
  else {
    for(int i= 0; i < chars.size(); i++) {
      char next = chars[i];
      if(!visited[next - 'A']) {
	bool valid = true;
	for(int j= 0; j < 26; j++) {
	  if(edges[next - 'A'][j] && visited[j]) {
	    valid = false;
	    break;
	  }
	}
	if(valid) {
	  visited[next - 'A'] = true;
	  generate(prefix + next);
	  visited[next - 'A'] = false;
	}
      }
    }
  }
}

int main() {
  int tc;
  cin >> tc;
  string line;
  getline(cin, line);
  for(int caseNo = 0; caseNo < tc; caseNo++) {
    if(caseNo != 0)
      cout << endl;
    getline(cin, line);
    getline(cin, line);
    istringstream iss(line.c_str());
    char eachchar;
    chars.clear();
    while(iss >> eachchar){
      chars.push_back(eachchar);
    } 
    sort(chars.begin(), chars.end());
    memset(edges, false, sizeof edges);
    getline(cin, line);
    istringstream iss2(line.c_str());
    string constraint;
    while(getline(iss2, constraint, ' ')) {
      edges[constraint[0] - 'A'][constraint[2] - 'A'] = true;
    }
    memset(visited, false, sizeof visited);
    solution = false;
    generate("");
    if(!solution)
      cout << "NO" << endl;
  }
  return 0;
}
