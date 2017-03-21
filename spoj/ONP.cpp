#include <cstdio>
#include <stack>
#include <cctype>

using namespace std;

const int maxl = 400;
char str[maxl+5];

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", str);
    stack<char> s;
    for(int i = 0; i >= 0; i++) {
      if(str[i] == '\0')
	break;
      if(isalpha(str[i])) {
	printf("%c", str[i]);
      } else if(str[i] == ')') {
	printf("%c", s.top());
	s.pop();
      } else if(str[i] != '(') {
	s.push(str[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
