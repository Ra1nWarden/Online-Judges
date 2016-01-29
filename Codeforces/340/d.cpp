#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;
Point points[3];

bool check_one() {
  if(points[0].first == points[1].first && points[1].first == points[2].first)
    return true;
  if(points[0].second == points[1].second && points[1].second == points[2].second)
    return true;
  return false;
}

bool check_two() {
  for(int i = 0; i < 3; i++) {
    for(int j = i + 1; j < 3; j++) {
      int k = 3 - i - j;
      if(points[k].first >= min(points[i].first, points[j].first) && points[k].first <= max(points[i].first, points[j].first) && points[k].second >= min(points[i].second, points[j].second) && points[k].second <= max(points[i].second, points[j].second)) {
	return points[k].first == points[i].first || points[k].first == points[j].first || points[k].second == points[i].second || points[k].second == points[j].second;
      }
    }
  }
  return false;
}

int main() {
  for(int i = 0; i < 3; i++)
    scanf("%d %d", &points[i].first, &points[i].second);
  if(check_one()) {
    printf("1\n");
  } else if(check_two()) {
    printf("2\n");
  } else {
    printf("3\n");
  }
  return 0;
}
