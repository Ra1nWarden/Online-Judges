#include <cstdio>
#include <algorithm>

using namespace std;

struct Rect {
  int a, b, c, i;
  bool operator<(const Rect& rhs) const {
    if(b != rhs.b) {
      return b < rhs.b;
    }
    if(c != rhs.c) {
      return c < rhs.c;
    }
    return a < rhs.a;
  }
};

const int maxn = 100000;
Rect v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  int maxv = 0;
  int maxi = 0;
  for(int i = 1; i <= n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int arr[3] = {a, b, c};
    sort(arr, arr+3);
    v[i] = Rect { arr[0], arr[1], arr[2], i };
    if(min(a, min(b, c)) > maxv) {
      maxv = min(a, min(b, c));
      maxi = i;
    }
  }
  sort(v + 1, v + n + 1);
  bool f = false;
  int maxa = 0, maxb = 0;
  for(int i = 1; i <= n - 1; i++) {
    if(v[i].b == v[i+1].b && v[i].c == v[i+1].c) {
      if(min(v[i].a + v[i+1].a, min(v[i].b, v[i].c)) > maxv) {
	f = true;
	maxv = min(v[i].a + v[i+1].a, min(v[i].b, v[i].c));
	maxa = v[i].i;
	maxb = v[i+1].i;
      }
    }
  }
  if(f) {
    printf("2\n%d %d\n", maxa, maxb);
  } else {
    printf("1\n%d\n", maxi);
  }
  return 0;
}
