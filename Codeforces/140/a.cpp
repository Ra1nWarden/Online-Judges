#include <cstdio>

using namespace std;

int main() {
  long long xa, ya, xb, yb, xc, yc;
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &xa, &ya, &xb, &yb, &xc, &yc);
  long long xab = xb - xa;
  long long yab = yb - ya;
  long long xbc = xc - xb;
  long long ybc = yc - yb;
  long long cross = (xab * ybc) - (yab * xbc);
  if(cross == 0) {
    printf("TOWARDS\n");
  } else if(cross < 0) {
    printf("RIGHT\n");
  } else {
    printf("LEFT\n");
  }
  return 0;
}
