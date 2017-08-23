#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1000;
char str[maxn+5];
long long b;

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s %lld\n", str, &b);
    if(b == 0) {
      printf("1\n");
      continue;
    }
    int dig = -1;
    for(int i = 0; i >= 0; i++) {
      if(str[i] == '\0')
	break;
      dig = str[i] - '0';
    }
    vector<int> v;
    v.push_back(dig);
    int cur = (dig * dig) % 10;
    while(cur != v[0]) {
      v.push_back(cur);
      cur = (cur * dig) % 10;
    }
    printf("%d\n", v[((b % v.size()) - 1 + v.size()) % v.size()]);
  }
  return 0;
}
