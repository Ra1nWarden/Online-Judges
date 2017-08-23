#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n, s;
    scanf("%d %d", &n, &s);
    printf("%s wins.\n", s ? "Pagfloyd" : "Airborne");
  }
  return 0;
}
