#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string firstline = "`1234567890-=";
  string secondline = "QWERTYUIOP[]\\";
  string thirdline = "ASDFGHJKL;\'";
  string fourthline = "ZXCVBNM,./";
  vector<string> allchars;
  allchars.push_back(firstline);
  allchars.push_back(secondline);
  allchars.push_back(thirdline);
  allchars.push_back(fourthline);
  char c;
  while(cin >> c) {
      if(c == 32 || c == 10)
	cout << c;
      else {
	string foundline;
	int foundindex;
	for(int i = 0; i < allchars.size(); i++) {
	  string currentline = allchars[i];
	  int currentfoundindex = currentline.find(c);
	  if(currentfoundindex != -1) {
	    foundline = currentline;
	    foundindex = currentfoundindex;
	    break;
	  }
	}
	cout << foundline[foundindex - 1];
      }
  }
  cout << endl;
  return 0;
}
