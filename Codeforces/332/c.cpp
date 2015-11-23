#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int arr[maxn+5];
int idx[maxn+5];
int ai;
int n;

typedef pair<int, bool> Point;
Point points[maxn*2+10];
int pi;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  pi = 0;
  ai = 0;
  idx[ai] = 0;
  arr[ai++] = v[0];
  points[pi++] = make_pair(0, true);
  for(int i = 1; i < n; i++) {
    int j = upper_bound(arr, arr+ai, v[i]) - arr;
    if(j == ai) {
      points[pi++] = make_pair(i, true);
      idx[ai] = i;
      arr[ai++] = v[i];
    } else {
      points[pi++] = make_pair(idx[j], true);
    }
  }
  ai = 0;
  idx[ai] = n-1;
  arr[ai++] = -v[n-1];
  points[pi++] = make_pair(n-1, false);
  for(int i = n - 2; i > -1; i--) {
    int j = upper_bound(arr, arr+ai, -v[i]) - arr;
    if(j == ai) {
      points[pi++] = make_pair(i, false);
      idx[ai] = i;
      arr[ai++] = -v[i];
    } else {
      points[pi++] = make_pair(idx[j], false);
    }
  }
  sort(points, points+pi);
  int ans = 0;
  int counter = 0;
  for(int i = 0; i < pi; i++) {
    if(i > 0 && points[i].first != points[i-1].first && counter == 0)
      ans++;
    if(points[i].second)
      counter++;
    else
      counter--;
  }
  printf("%d\n", ans + 1);
  return 0;
}
