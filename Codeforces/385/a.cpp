#include <cstdio>
#include <string>
#include <set>
#include <sstream>

using namespace std;

const int maxl = 50;
char str[maxl+5];

int main() {
  scanf("%s", str);
  set<string> s;
  for(int i = 0; i >= 0; i++) {
    if(str[i] == '\0')
      break;
    stringstream ss;
    for(int j = i; j >= 0; j++) {
      if(str[j] == '\0')
	break;
      ss << str[j];
    }
    for(int j = 0; j < i; j++) {
      ss << str[j];
    }
    string word = ss.str();
    if(s.count(word))
      break;
    s.insert(word);
  }
  printf("%d\n", s.size());
  return 0;
}
