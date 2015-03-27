#include <cstdio>
#include <bitset>

using namespace std;

int main() {
  int h;
  long long n;
  scanf("%d %I64d", &h, &n);
  bitset<50> bits(n - 1);
  long long result = 0;
  bool right = false;
  for(int i = h - 1; i >= 0; i--) {
    if(bits[i] == right) {
      result += 1;
      right = !right;
    } else {
      result += (1LL << (i + 1));
      if(i != h - 1)
	right = !bits[i + 1];
    }
  }
  printf("%I64d\n", result);
  return 0;
}
