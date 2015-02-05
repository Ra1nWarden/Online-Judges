#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

map<string, int> wordIndex;

int main() {
  queue<string> q;
  for(char i= 'a'; i <= 'z'; i++) {
    string word = "";
    word += i;
    q.push(word);
  }
  int bfsindex = 1;
  while(!q.empty()) {
    string next = q.front();
    q.pop();
    wordIndex[next] = bfsindex++;
    if(next.length() < 5) {
      char last = next[next.length() - 1];
      for(char i= (char) (last + 1); i <= 'z'; i++) {
	q.push(next + i);
      }
    }
  }
  string line;
  while(getline(cin, line)) {
    if(wordIndex.count(line) == 0)
      cout << 0 << endl;
    else
      cout << wordIndex[line] << endl;
  }
  return 0;
}
