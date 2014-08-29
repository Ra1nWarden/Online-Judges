#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  int cases;
  cin >> cases >> ws;
  string line;
  for(int i = 0; i < cases; i++) {
    map<string, int> treeCount;
    if (i != 0)
      cout << endl;
    int trees = 0;
    while(true) {
      getline(cin, line);
      if(line == "")
	break;
      trees++;
      if(treeCount.count(line) == 0)
	treeCount[line] = 1;
      else
	treeCount[line] = treeCount[line] + 1;
    }
    for(map<string, int>::iterator itr = treeCount.begin(); itr != treeCount.end(); itr++) {
      printf("%s %.4f\n", itr->first.c_str(), ((double) itr->second) * 100 / trees);
    }
  }
  return 0;
}
