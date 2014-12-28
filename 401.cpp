#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

map<char, char> mirror;

void init() {
  mirror['A'] = 'A';
  mirror['E'] = '3';
  mirror['H'] = 'H';
  mirror['I'] = 'I';
  mirror['J'] = 'L';
  mirror['L'] = 'J';
  mirror['M'] = 'M';
  mirror['O'] = 'O';
  mirror['S'] = '2';
  mirror['T'] = 'T';
  mirror['U'] = 'U';
  mirror['V'] = 'V';
  mirror['W'] = 'W';
  mirror['X'] = 'X';
  mirror['Y'] = 'Y';
  mirror['Z'] = '5';
  mirror['1'] = '1';
  mirror['2'] = 'S';
  mirror['3'] = 'E';
  mirror['5'] = 'Z';
  mirror['8'] = '8';
}
 
bool palidrome(string line) {
  if(line.length() == 1)
    return true;
  for(int i = 0; i < line.length() / 2; i++) {
    if(line[i] != line[line.length() - 1 - i])
      return false;
  }
  return true;
}

bool mirrortest(string line) {
  if(line.length() == 1) {
    if(mirror.count(line[0]) == 0)
      return false;
    else
      return mirror[line[0]] == line[0];
  }
  for(int i = 0; i < line.length() / 2; i++) {
    char first = line[i];
    char second = line[line.length() - 1 - i];
    bool firstcontain = mirror.count(first);
    bool secondcontain = mirror.count(second);
    if(firstcontain && secondcontain) {
      if(mirror[first] != second)
	return false;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  init();
  string line;
  while(getline(cin, line)) {
    bool pal = palidrome(line);
    bool mir = mirrortest(line);
    if(pal && mir) {
      printf("%s -- is a mirrored palindrome.\n\n", line.c_str());
    } else if (mir) {
      printf("%s -- is a mirrored string.\n\n", line.c_str());
    } else if (pal) {
      printf("%s -- is a regular palindrome.\n\n", line.c_str());
    } else {
      printf("%s -- is not a palindrome.\n\n", line.c_str());
    }
  }
  return 0;
}
