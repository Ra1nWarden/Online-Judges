#include <cstdio>
#include <map>

using namespace std;

const int maxl = 18;
char str[maxl+5];

int translate() {
  int ans = 0;
  for(int i = 0; i >= 0; i++) {
    if(str[i] == '\0')
      break;
    ans <<= 1;
    int num = str[i] - '0';
    if(num & 1) {
      ans |= 1;
    }
  }
  return ans;
}

int main() {
  map<int, int> s;
  int n;
  scanf("%d\n", &n);
  while(n--) {
    char op;
    scanf("%c %s\n", &op, str);
    int num = translate();
    if(op == '+') {
      if(s.count(num))
	s[num] = s[num] + 1;
      else
	s[num] = 1;
    } else if(op == '-') {
      s[num] = s[num] -  1;
    } else {
      printf("%d\n", s[num]);
    }
  }
  return 0;
}
