#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
  long long totaltime = 100 * 60 * 60 * 24;
  while(true) {
    string line;
    getline(cin, line);
    if(!cin)
      break;
    vector<int> digits;
    for(int i = 0; i < 8; i += 2) {
      int digit = atoi(line.substr(i, 2).c_str());
      digits.push_back(digit);
    }
    long long time = digits[3];
    time += 100 * digits[2];
    time += 100 * 60 * digits[1];
    time += 100 * 60 * 60 * digits[0];
    printf("%07lld\n", time * 10000000 / totaltime);
  }
  return 0;
}
