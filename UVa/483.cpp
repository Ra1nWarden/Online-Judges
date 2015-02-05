#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string line;
  while(true) {
    getline(cin, line);
    if (!cin)
      break;
    istringstream iss(line);
    string word;
    bool begin = true;
    while (iss >> word) {
      if (!begin)
	cout << " ";
      for(int i = word.length() - 1; i >= 0; i--) {
	cout << word[i];
      }
      begin = false;
    }
    cout << endl;
  }
  return 0;
}
