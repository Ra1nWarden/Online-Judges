#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string converted[26] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};

string convert(char c) {
  int v = c - 'a';
  if(v < 0 || v >= 26) {
    v = c - 'A';
  }
  if(v < 0 || v >= 26) {
    stringstream ss;
    ss << c;
    return ss.str();
  }
  return converted[v];
}

const int maxn = 10000;
char str[maxn+5];

int main() {					
  ios::sync_with_stdio(false);
  string line;
  getline(cin, line);
  stringstream ss;
  for(int i = 0; i < line.length(); i++) {
    char c = line[i];
    ss << convert(c);
  }
  printf("%s\n", ss.str().c_str());
  return 0;
}
