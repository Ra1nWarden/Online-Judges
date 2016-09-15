#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
  set<int> s;
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    s.insert(x);
    if(s.size() > 3) {
      printf("NO\n");
      return 0;
    }
  }
  vector<int> v(s.begin(), s.end());
  if(v.size() < 3) {
    printf("YES\n");
  } else {
    printf("%s\n", v[1] - v[0] == v[2] - v[1] ? "YES" : "NO");
  }
  return 0;
}
