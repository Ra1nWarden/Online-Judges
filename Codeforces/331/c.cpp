#include <queue>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 100000;
typedef pair<int, int> II;
map<int, queue<int> > m;
map<II, int> ranks;
int n;
II points[maxn+5];
II sorted[maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &points[i].first, &points[i].second);
  }
  for(int i = 0; i < n; i++) {
    int score;
    scanf("%d", &score);
    m[score].push(i);
  }
  sort(points, points+n);
  bool ok = true;
  for(int i = 0; i < n; i++) {
    int diff = points[i].second - points[i].first;
    if(m.count(diff) == 0 || m[diff].empty()) {
      ok = false;
      break;
    }
    int rank = m[diff].front();
    m[diff].pop();
    ranks[points[i]] = rank;
    sorted[rank] = points[i];
    II left = make_pair(points[i].first - 1, points[i].second);
    II down = make_pair(points[i].first, points[i].second - 1);
    II right = make_pair(points[i].first + 1, points[i].second);
    II up = make_pair(points[i].first, points[i].second + 1);
    if(ranks.count(left) && ranks[left] > rank) {
      ok = false;
      break;
    }
    if(ranks.count(down) && ranks[down] > rank) {
      ok = false;
      break;
    }
    if(ranks.count(up) && ranks[up] < rank) {
      ok = false;
      break;
    }
    if(ranks.count(right) && ranks[right] < rank) {
      ok = false;
      break;
    }
  }
  if(ok) {
    printf("YES\n");
    for(int i = 0; i < n; i++) {
      printf("%d %d\n", sorted[i].first, sorted[i].second);
    }
  } else {
    printf("NO\n");
  }
  return 0;
}
