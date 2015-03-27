#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> interval;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<interval> intervals;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      intervals.push_back(make_pair(i, j));
    }
  }
  //printf("intervals has size %lu\n", intervals.size());
  int v[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  long long totalinv = 0;
  //printf("k is %d\n", k);
  //printf("power is %d\n", (int) pow(intervals.size(), k));
  for(int i = 0; i < (int) pow(intervals.size(), k); i++) {
    //printf("looping i = %d\n", i);
    int vcpy[n];
    memcpy(vcpy, v, sizeof v);
    int ip = i;
    for(int j = 0; j < k; j++) {
      int changei = ip % intervals.size();
      //printf("%d -> ", changei);
      reverse(vcpy + intervals[changei].first, vcpy + intervals[changei].second + 1);
      //printArray(vcpy, n);
      ip /= intervals.size();
    }
    //printf("\n");
    for(int j = 0; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
	if(vcpy[j] > vcpy[k])
	  totalinv++;
      }
    }

  }
  printf("%.10lf\n", totalinv / (double) pow(intervals.size(), k));

  return 0;
}
