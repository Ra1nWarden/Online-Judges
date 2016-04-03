#include <cstdio>
#include <list>
#include <cstring>
#include <map>
#include <string>

using namespace std;

const int maxl = 10;
char str[maxl+1];
map<string, list<string>::iterator> m;
list<string> l;

int main() {
  int n;
  scanf("%d\n", &n);
  while(n--) {
    scanf("%s\n", str);
    string s(str);
    if(m.count(s)) {
      l.erase(m[s]);
    }
    l.push_front(s);
    m[s] = l.begin();
  }
  for(list<string>::iterator itr = l.begin(); itr != l.end(); itr++)
    printf("%s\n", itr->c_str());
  return 0;
}
