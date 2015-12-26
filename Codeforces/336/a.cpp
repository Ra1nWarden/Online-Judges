#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 100;
typedef pair<int, int> Node;
Node people[maxn+1];
int n;
int s;

bool _cmp(const Node& a, const Node& b) {
  if(a.first != b.first)
    return a.first > b.first;
  return a.second < b.second;
}

int main() {
  scanf("%d%d", &n, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &people[i].first, &people[i].second);
  }
  sort(people, people + n, _cmp);
  int time = 0;
  int floor = s;
  for(int i = 0; i < n; i++) {
    time += (floor - people[i].first);
    floor = people[i].first;
    if(time < people[i].second)
      time = people[i].second;
  }
  time += floor;
  printf("%d\n", time);
  return 0;
}
