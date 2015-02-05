#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <sstream>

using namespace std;

bool DEBUG = false;

struct Node {
  vector<int> indices;
  map<char, int> m;
  Node() {};
  Node(const Node& another) {
    m = another.m;
    indices = another.indices;
  };
  Node(string str) {
    for(int i = 0; i < str.length(); i++) {
      if(str[i] == ' ')
	continue;
      if(m.count(str[i]))
	m[str[i]] += 1;
      else
	m[str[i]] = 1;
    }
  };
  bool operator<(Node& another) {
    for(map<char, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
      if(!another.m.count(itr->first) || itr->second > another.m[itr->first])
	return false;
    }
    return true;
  };
  // remember to update indices after calling operator-
  Node operator-(Node& rhs) {
    //cout << "in operator- " << endl;
    Node result(*this);
    for(map<char, int>::iterator itr = rhs.m.begin(); itr != rhs.m.end(); itr++) {
      //cout << "before: " << result.m[itr->first] << endl;
      result.m[itr->first] -= itr->second;
      //cout << "after: " << result.m[itr->first] << endl;
    }
    return result;
  };
  bool empty() {
    for(map<char, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
      if(itr->second != 0)
	return false;
    }
    return true;
  };
};

vector<string> dict;
vector<Node> nodes;

int main() {
  string word;
  while(getline(cin, word)) {
    if(word == "#")
      break;
    if(DEBUG)
      cout << "word is " << word << endl;
    dict.push_back(word);
    nodes.push_back(Node(word));
  }
  if(DEBUG)
    cout << "here 1" << endl;
  string line;
  if(DEBUG)
    cout << "before while loop" << endl;
  while(getline(cin, line)) {
    if(DEBUG)
      cout << "here 2" << endl;
    if(line == "#")
      break;
    Node start(line);
    // cout << line << " has: " << endl;
    // for(map<char, int>::iterator itr = start.m.begin(); itr != start.m.end(); itr++)
    //   cout << itr->first << " -> " << itr->second << "; ";
    // cout << endl;

    stack<Node> s;
    s.push(start);
    set<string> prints;
    if(DEBUG)
      cout << "here before while" << endl;
    while(!s.empty()) {
      Node next = s.top();
      s.pop();
      if(DEBUG)
	cout << "here" << endl;
      if(next.empty()) {
	if(DEBUG)
	  cout << "empty" << endl;
	vector<int> printi = next.indices;
	sort(printi.begin(), printi.end());
	string printword = "";
	for(int i = 0; i < printi.size(); i++) {
	  if(i != 0)
	    printword += " ";
	  printword += dict[printi[i]];
	}
	prints.insert(printword);
      } else {
	if(DEBUG)
	  cout << "else branch" << endl;
	for(int i = 0; i < nodes.size(); i++) {
	  if(DEBUG)
	    cout << "nodes iteration" << endl;
	  if(nodes[i] < next) {
	    if(DEBUG)
	      cout << "subtracted" << endl;
	    // cout << "before subtract" << endl;
	    // for(map<char, int>::iterator itr = next.m.begin(); itr != next.m.end(); itr++)
	    //   cout << itr->first << " has " << itr->second << " ";
	    // cout << endl;

	    Node newnode = next - nodes[i];

	    // cout << "after subtract" << endl;
	    // for(map<char, int>::iterator itr = newnode.m.begin(); itr != newnode.m.end(); itr++)
	    //   cout << itr->first << " has " << itr->second << " ";
	    // cout << endl;

	    newnode.indices.push_back(i);
	    // cout << line << " has a match " << endl;
	    // for(int j = 0; j < newnode.indices.size(); j++)
	    //   cout << dict[newnode.indices[j]] << " ";
	    // cout << endl;

	    //cout << "for string " << line << ": there is match" << endl;
	    s.push(newnode);
	  } else if(DEBUG)
	    cout << "greater than " << endl;
	}
      }
    }
    stringstream ss(line.c_str());
    vector<string> sortedlinev;
    string wordsorted;
    while(ss >> wordsorted)
      sortedlinev.push_back(wordsorted);
    sort(sortedlinev.begin(), sortedlinev.end());
    string sortedline = "";
    for(int j = 0; j < sortedlinev.size(); j++) {
      if(j != 0)
	sortedline += " ";
      sortedline += sortedlinev[j];
    }
    for(set<string>::iterator itr = prints.begin(); itr != prints.end(); itr++) {
      if(*itr == sortedline)
	continue;
      printf("%s = %s\n", line.c_str(), itr->c_str());
    }

  }
  return 0;
}
