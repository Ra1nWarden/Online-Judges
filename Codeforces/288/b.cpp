#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  string line;
  getline(cin, line);
  string result = "";
  for(int i = 0; i < line.length() - 1; i++) {
    if((line[i] - '0')  % 2 == 0 && (line[i]  < line[line.length() - 1])) {
      swap(line[i], line[line.length() - 1]);
      printf("%s\n", line.c_str());
      return 0;
    }
  }
  for(int i = line.length() - 2; i >= 0; i--) {
    if((line[i] - '0') % 2 == 0) {
      swap(line[i], line[line.length() - 1]);
      printf("%s\n", line.c_str());
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
