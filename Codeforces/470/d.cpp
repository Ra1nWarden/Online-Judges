#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
const int maxn = 300000;
int a[maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> keys;
  int p;
  for(int i = 0; i < n; i++) {
    scanf("%d", &p);
    keys.push_back(p);
  }
  sort(keys.begin(), keys.end());
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    auto l = keys.begin();
    auto r = keys.end();
    int bit = 29;
    int run = 0;
    while(bit >= 0) {
      if(a[i] & (1 << bit)) {
	auto new_l = lower_bound(l, r, run | (1 << bit));
	if(new_l != r) {
	  l = new_l;
	  run |= (1 << bit);
	}
      } else {
	auto new_r = lower_bound(l, r, run | (1 << bit));
	if(new_r != l) {
	  r = new_r;
	} else {
	  run |= (1 << bit);
	}
      }
      bit--;
    }
    printf("%d", a[i] ^ (*l));
    keys.erase(l);
  }
  printf("\n");
  return 0;
}
