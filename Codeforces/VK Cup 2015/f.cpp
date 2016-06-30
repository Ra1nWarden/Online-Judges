#include <cstdio>
#define MAXN 1005

using namespace std;

struct Quest {
  int t, q;
  Quest() {}
  bool operator<(const Quest& rhs) const {
    if(t != rhs.t) {
      return t < rhs.t;
    }
    return q < rhs.q;
  }
};

Quest quests[MAXN];
int n, t;

int main() {
  scanf("%d", &n, &t);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &quests[i].t, &quests[i].q);
  }
  
  return 0;
}
