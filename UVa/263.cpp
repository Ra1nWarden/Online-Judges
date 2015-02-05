#include <iostream>
#include <sstream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  int num;
  while(cin >> num && num) {
    printf("Original number was %d\n", num);
    set<int> visited;
    int prev = num;
    while(true) {
      string prevs;
      stringstream ss;
      ss << prev;
      ss >> prevs;
      sort(prevs.begin(), prevs.end(), less<int>());
      stringstream lessstream(prevs.c_str());
      int small;
      lessstream >> small;
      sort(prevs.begin(), prevs.end(), greater<int>());
      stringstream greaterstream(prevs.c_str());
      int big;
      greaterstream >> big;
      prev = big - small;
      printf("%d - %d = %d\n", big, small, prev);
      if(visited.count(prev))
	break;
      visited.insert(prev);
    }
    printf("Chain length %lu\n\n", visited.size() + 1);
  }
  return 0;
}
