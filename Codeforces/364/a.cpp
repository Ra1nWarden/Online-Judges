#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 100;
int n;
typedef pair<int, int> Card;
Card cards[maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    cards[i] = make_pair(num, i);
  }
  sort(cards+1, cards+n+1);
  for(int i = 1; i <= n / 2; i++) {
    printf("%d %d\n", cards[i].second, cards[n-i+1].second);
  }
  return 0;
}
