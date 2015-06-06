#include <cstdio>
#include <cstring>
#include <sstream>
#define MAXL 105

using namespace std;

char num[MAXL];
int len;
int target;

int main() {
  scanf("%s", num);
  len = strlen(num);
  bool success = false;
  for(target = 0; target < 1000; target += 8) {
    stringstream ss;
    ss << target;
    string target_str = ss.str();
    int index = 0;
    for(int i = 0; i < len && index < target_str.length(); i++) {
      if(num[i] == target_str[index]) {
	index++;
      }
    }
    if(index == target_str.length()) {
      printf("YES\n%d\n", target);
      success = true;
      break;
    }
  }
  if(!success)
    printf("NO\n");
  return 0;
}

