#include <cstdio>
#include <sstream>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i > 0; i++) {
    stringstream ss;
    ss << (n+i);
    string str = ss.str();
    //printf("string is %s\n", str.c_str());
    for(int j = 0; j < str.length(); j++) {
      if(str[j] == '8') {
	printf("%d\n", i);
	return 0;
      }
    }
  }
  return 0;
}
