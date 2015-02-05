#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool rules[26][26];
int inDegree[26];
vector<char> sorted;
bool visited[26];

void toposort(int u) {
  // cout << "calling toposort on " << (char)(u+'A') << endl;
  visited[u] = true;
  for(int i=  0; i < 26; i++) {
    if(rules[u][i] && !visited[i]) {
      toposort(i);
    }
  }
  sorted.push_back(u);
}

int main() {
  string line;
  vector<string> lines;
  while(getline(cin, line)) {
    if(line == "#")
      break;
    lines.push_back(line);
  }
  memset(inDegree, -1, sizeof inDegree);
  memset(rules, false, sizeof rules);
  memset(visited, false, sizeof visited);
  for(int i= 0; i < lines.size() - 1; i++) {
    string first = lines[i];
    string second = lines[i+1];
    for(int j= 0;; j++){
      if(j >= first.length() || j >= second.length())
	break;					
      char firstc = first[j];
      char secondc = second[j];
      inDegree[firstc - 'A'] = 0;
      inDegree[secondc - 'A'] = 0;
      if(firstc != secondc) {
	rules[firstc - 'A'][secondc -'A'] = true;
	break;
      }
    }
  }
  sorted.clear();
  for(int i= 0; i < 26; i++) {
    if(inDegree[i] == 0 && !visited[i]) {
      toposort(i);
    }
  }
  for(int i= sorted.size() - 1; i >=0; i--) {
    cout << (char) (sorted[i] + 'A');
  }
  cout << endl;

  return 0;
}
