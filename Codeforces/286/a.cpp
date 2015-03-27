#include <iostream>

using namespace std;

int main() {
  string line;
  getline(cin, line);
  bool ok = true;
  for(int i = 0; i < line.length() / 2; i++) {
    if(line[i] != line[line.length() - 1 - i]) {
      ok = false;
      break;
    }
  }
  if(ok) {
    if(line.length() % 2 == 0) {
      cout << line.substr(0, line.length() / 2) << "a" << line.substr(line.length() / 2) << endl;
      return 0;
    } else {
      cout << line.substr(0, line.length() / 2) << line[line.length() / 2] << line.substr(line.length() / 2) << endl;
      return 0;
    }
  } else {
    string newline1, newline2;
    for(int i = 0; i < line.length() / 2; i++) {
      if(line[i] != line[line.length() - 1 - i]) {
	newline1 = line.substr(0, line.length() - i) + line[i];
	if(i != 0)
	  newline1 += line.substr(line.length() - i);
	if(i != 0)
	  newline2 = line.substr(0, i);
	else
	  newline2 = "";
	newline2 += line[line.length() - 1 - i] + line.substr(i);
	break;
      }
    }
    //cout << "line1 is " << newline1 << " line2 is " << newline2 << endl;
    bool ok = true;
    for(int i = 0; i < newline1.length() / 2; i++) {
      if(newline1[i] != newline1[newline1.length() - 1 - i]) {
	ok = false;
	break;
      }
    }
    if(ok) {
      cout << newline1 << endl;
      return 0;
    }
    ok = true;
    for(int i= 0; i < newline2.length() / 2; i++) {
      if(newline2[i] != newline2[newline2.length() - i - 1]) {
	ok = false;
	break;
      }
    }
    if(ok) {
      cout << newline2 << endl;
    } else {
      cout << "NA" << endl;
    }
  }
  return 0;
}
