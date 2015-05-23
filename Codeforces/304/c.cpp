#include <cstdio>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

int n;
typedef pair<long long, long long> LL;
set<LL> seen;

int main() {
  scanf("%d", &n);
  int v1, v2;
  scanf("%d", &v1);
  long long m1 = 0, m2 = 0;
  queue<int> q1, q2;
  for(int i = 0; i < v1; i++) {
    int x;
    scanf("%d", &x);
    q1.push(x);
    m1 += (i == 0 ? 1 : 11LL * i) * x;
  }
  scanf("%d", &v2);
  for(int i = 0; i < v2; i++) {
    int x;
    scanf("%d", &x);
    q2.push(x);
    m2 += (i == 0 ? 1 : 11LL * i) * x;
  }
  int ans = 0;
  seen.insert(make_pair(m1, m2));
  while((!q1.empty()) && (!q2.empty())) {
    int c1 = q1.front();
    q1.pop();
    int c2 = q2.front();
    q2.pop();
    m1 /= 11;
    m2 /= 11;
    if(c1 > c2) {
      m1 += (q1.empty() ? 1 : 11LL * q1.size()) * c2;
      q1.push(c2);
      m1 += (q1.empty() ? 1 : 11LL * q1.size()) * c1;
      q1.push(c1);
    } else {
      m2 += (q2.empty() ? 1 : 11LL * q2.size()) * c1;
      q2.push(c1);
      m2 += (q2.empty() ? 1 : 11LL * q2.size()) * c2;
      q2.push(c2);
    }
    LL next = make_pair(m1, m2);
    if(seen.count(next)) {
      ans = -1;
      break;
    }
    seen.insert(next);
    ans++;
  }
  if(ans == -1)
    printf("-1\n");
  else {
    printf("%d ", ans);
    if(q1.empty()) {
      printf("2\n");
    } else {
      printf("1\n");
    }
  }
  return 0;
}
