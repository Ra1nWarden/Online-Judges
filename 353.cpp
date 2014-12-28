#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main() {
  string line;
  while(getline(cin, line)) {
    set<string> s;
    for(int i = 0; i < line.length(); i++)
      s.insert(line.substr(i, 1));
    for(int i = 0; i < line.length(); i++) {
      for(int j = 1; j > -1; j++) {
	if(i - j < 0 || i + j >= line.length())
	  break;
	if(line[i-j] == line[i+j]) {
	  s.insert(line.substr(i-j, 2 * j + 1));
	} else
	  break;
      }
    }
    for(int i = 0; i+1 < line.length(); i++) {
      if(line[i] == line[i+1]) {
	s.insert(line.substr(i, 2));
	for(int j = 1; j < line.length(); j++) {
	  if(i - j < 0 || i + j + 1 >= line.length())
	    break;
	  if(line[i-j] == line[i+1+j]) {
	    s.insert(line.substr(i-j, 2 * j + 2));
	  } else
	    break;
	}
      }
    }
    printf("The string \'%s\' contains %lu palindromes.\n", line.c_str(), s.size());
  }
  return 0;
}
