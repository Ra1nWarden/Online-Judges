#include <cstdio>
#include <set>
#include <string>

using namespace std;

char id[6];

int main() {
  int n;
  scanf("%d\n", &n);
  set<string> a, b;
  while(n--) {
    scanf("%s", id);
    a.insert(string(id));
    int m;
    scanf("%d", &m);
    while(m--) {
      scanf("%s", id);
      b.insert(string(id));
    }
  }
  int ans = 0;
  for(set<string>::iterator itr = b.begin(); itr != b.end(); itr++) {
    if(!a.count(*itr)) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
