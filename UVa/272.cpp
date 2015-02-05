#include <iostream>
#include <string>

using namespace std;

int main() {
  string line;
  bool openDouble = true;
  while(true) {
    getline(cin, line);
    if (!cin)
      break;
    for(int i = 0; i < line.length(); i++) {
      if(line[i] == '\"') {
	if(openDouble) {
	  cout << "``";
	  openDouble = false;
	}
	else {
	  cout << "\'\'";
	  openDouble = true;
	}
      }
      else
	cout << line[i];
     }
    cout << endl;
  }
  return 0;
}
