#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string evaluate(string& exps) {
  
}

int main() {
  int cases;
  cin >> cases >> ws >> ws;
  for(int i= 0; i < cases; i++) {
    stack<string> exps;
    string buffer = "";
    string result = "";
    string line;
    while(true) {
      getline(cin, line);
      if(line == "")
	break;
      else if(line == "(") {
	exps.push(buffer);
	buffer = "";
      }
      else if(line == ")") {
	result += evaluate(buffer);
	buffer = exps.top();
	exps.pop();
      }
      else {
	buffer += line;
      }
    }
    cout << result << endl;
  }
  return 0;
}
