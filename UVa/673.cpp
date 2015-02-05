#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  int cases;
  cin >> cases >> ws;
  for(int i=  0 ;i < cases; i++) {
    string line;
    getline(cin, line);
    stack<char> currentLine;
    bool balanced = true;
    for(int j = 0; j < line.length(); j++) {
      if(line[j] == '(' || line[j] == '[')
	currentLine.push(line[j]);
      else {
	char next = line[j];
	if (currentLine.empty()) {
	  balanced = false;
	  break;
	}
	if(next == ')' && currentLine.top() != '(') {
	  balanced = false;
	  break;
	}
	else if (next == ']' && currentLine.top() != '[') {
	  balanced = false;
	  break;
	}
	else
	  currentLine.pop();
      }
    }
    if (!currentLine.empty())
      balanced = false;
    if(balanced)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
