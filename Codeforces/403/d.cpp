#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 1000;
typedef pair<string, string> Node;
Node nodes[maxn+5];
bool choice[maxn+5];
int n;
map<string, int> dict1, dict2;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> ws;
  string line;
  memset(choice, false, sizeof choice);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    string w1, w2;
    stringstream ss(line);
    ss >> w1 >> w2;
    nodes[i] = make_pair(w1.substr(0, 3), w1.substr(0, 2) + w2[0]);
    if(dict1.count(nodes[i].first)) {
      dict1[nodes[i].first] = dict1[nodes[i].first] + 1;
    } else {
      dict1[nodes[i].first] = 1;
    }
  }
  bool ok = true;
  while(true) {
    bool changed = false;
    for(int i = 0; i < n; i++) {
      if(choice[i]) {
	continue;
      } else {
	if(dict1[nodes[i].first] > 1) {
	  if(dict2.count(nodes[i].second)) {
	    ok = false;
	    break;
	  } else {
	    choice[i] = true;
	    changed = true;
	    dict2[nodes[i].second] = 1;
	  }
	} else if(dict2.count(nodes[i].first)) {
	  if(dict2.count(nodes[i].second)) {
	    ok = false;
	    break;
	  } else {
	    dict2[nodes[i].second] = 1;
	    choice[i] = true;
	    changed = true;
	  }
	}
      }
    }
    if(!ok || !changed)
      break;
  }
  if(!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
      cout << (choice[i] ? nodes[i].second : nodes[i].first) << endl;
  }
  return 0;
}
