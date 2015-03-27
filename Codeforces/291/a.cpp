#include <iostream>

using namespace std;

int main() {
  string line;
  getline(cin, line);
  for(int i = 0; i < line.length(); i++) {
    if(line[i] >= '5') {
      if(i == 0 && line[i] == '9')
	continue;
      line[i] = '9' - line[i] + '0';
    }
  }
  cout << line << endl;
  return 0;
}
