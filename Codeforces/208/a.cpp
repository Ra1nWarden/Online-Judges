#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  bool ok = true;
  for(int i = 2; i < n; i++) {
    for(int j = 1; j < i; j++) {
      pair<int, int> a = make_pair(min(v[i], v[i-1]), max(v[i], v[i-1]));
      pair<int, int> b = make_pair(min(v[j], v[j-1]), max(v[j], v[j-1]));
      if(a.first > b.first && a.first < b.second && a.second > b.second) {
	ok = false;
	break;
      }
      if(b.first > a.first && b.first < a.second && b.second > a.second) {
	ok = false;
	break;
      }
    }
    if(!ok) {
      break;
    }
  }
  printf("%s\n", ok ? "no" : "yes");
  return 0;
}
