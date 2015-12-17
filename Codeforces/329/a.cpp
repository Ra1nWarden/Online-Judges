#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000;
char str[maxn+5];
struct Node {
  pair<char, char> key;
  int len;
  Node(char a, char b, int l) {
    key = make_pair(min(a, b), max(a, b));
    len = l;
  }
};

int main() {
  int n;
  scanf("%d\n", &n);
  vector<Node> v;
  for(int i = 0; i < n; i++) {
    scanf("%s\n", str);
    char a = 0, b = 0;
    bool ok = true;
    for(int j = 0; j < strlen(str); j++) {
      if(a == 0) {
	a = str[j];
      } else if(a != str[j] && b == 0) {
	b = str[j];
      } else if(a != str[j] && b != str[j]) {
	ok = false;
	break;
      }
    }
    if(ok) {
      if(b == 0)
	b = a;
      v.push_back(Node(a, b, strlen(str)));
    }
  }
  int ans = 0;
  for(char i = 'a'; i <= 'z'; i++) {
    for(char j = i; j <= 'z'; j++) {
      int sub = 0;
      for(int k = 0; k < v.size(); k++) {
	if(v[k].key.first != v[k].key.second) {
	  if(i != v[k].key.first || j != v[k].key.second)
	    continue;
	} else {
	  if(i != v[k].key.first && j != v[k].key.second)
	    continue;
	}
	sub += v[k].len;
      }
      ans = max(ans, sub);
    }
  }
  printf("%d\n", ans);
  return 0;
}
