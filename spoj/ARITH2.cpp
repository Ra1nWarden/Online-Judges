#include <iostream>
#include <sstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string line;
  getline(cin, line);
  stringstream ss(line.c_str());
  int tc;
  ss >> tc;
  while(tc--) {
    getline(cin, line);
    getline(cin, line);
    stringstream iss(line.c_str());
    string token;
    string op = "";
    long long num1, num2;
    iss >> num1;
    while(true) {
      if(op == "") {
	iss >> op;
      } else {
	iss >> num2;
	if(op == "+") {
	  num1 += num2;
	} else if(op == "-") {
	  num1 -= num2;
	} else if(op == "*") {
	  num1 *= num2;
	} else if(op == "/") {
	  num1 /= num2;
	} else if(op == "=") {
	  cout << num1 << endl;
	  break;
	}
	op = "";
      }
    }
  }
  return 0;
}
