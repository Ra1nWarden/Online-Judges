#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

typedef pair<long long, int> Node;

const int maxn = 200000;
long long v[maxn+5];

struct Comp {
  bool operator()(const Node& a, const Node& b) const {
    long long aa = a.first < 0 ? -a.first : a.first;
    long long bb = b.first < 0 ? -b.first : b.first;
    return aa > bb;
  }
};

int main() {
  int n, k, x;
  scanf("%d%d%d", &n, &k, &x);
  int zero = 0;
  int neg = 0;
  priority_queue<Node, vector<Node>, Comp> pq;
  long long num;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", &num);
    if(num == 0)
      zero++;
    else if(num < 0)
      neg++;
    pq.push(make_pair(num, i));
  }
  for(int i = 0; i < k; i++) {
    long long u = pq.top().first;
    int ui = pq.top().second;
    pq.pop();
    if(u == 0) {
      zero--;
    } else if(u < 0) {
      neg--;
    }
    if(zero) {
      u = u - x;
    } else if(neg & 1) {
      u = u + x;
    } else {
      u = u - x;
    }
    if(u == 0) {
      zero++;
    } else if(u < 0) {
      neg++;
    }
    pq.push(make_pair(u, ui));
  }
  while(!pq.empty()) {
    Node u = pq.top();
    pq.pop();
    v[u.second] = u.first;
  }
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%I64d", v[i]);
  }
  printf("\n");
  return 0;
}
