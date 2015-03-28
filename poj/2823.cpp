#include <cstdio>
#include <utility>
#define MAXN 1000005

using namespace std;

int n, k;
int v[MAXN];
typedef pair<int, int> II;

II minArr[MAXN];
int minHead, minTail;
II maxArr[MAXN];
int maxHead, maxTail;
int ans[MAXN][2];

void insert(II x, bool maxVal) {
  if(maxVal) {
    while(maxHead < maxTail && maxArr[maxTail - 1].first < x.first)
      maxTail--;
    maxArr[maxTail] = x;
    maxTail++;
  } else {
    while(minHead < minTail && minArr[minTail - 1].first > x.first)
      minTail--;
    minArr[minTail] = x;
    minTail++;
  }
}

int topVal(int i, bool maxVal) {
  if(maxVal) {
    while(maxHead < maxTail && maxArr[maxHead].second < i)
      maxHead++;
    return maxArr[maxHead].first;
  } else {
    while(minHead < minTail && minArr[minHead].second < i)
      minHead++;
    return minArr[minHead].first;
  }
}

int main() {
  scanf("%d %d", &n, &k);
  minHead = minTail = maxHead = maxTail = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for(int i = 0; i < k; i++) {
    insert(make_pair(v[i], i), false);
    insert(make_pair(v[i], i), true);
  }
  for(int i = k; i <=  n; i++) {
    ans[i - k][0] = topVal(i - k, false);
    ans[i - k][1] = topVal(i - k, true);
    if(i < n) {
      insert(make_pair(v[i], i), false);
      insert(make_pair(v[i], i), true);
    }
  }
  for(int i = 0; i < n - k + 1; i++) {
    if(i > 0)
      printf(" ");
    printf("%d", ans[i][0]);
  }
  printf("\n");
  for(int i = 0; i < n - k + 1; i++) {
    if(i > 0)
      printf(" ");
    printf("%d", ans[i][1]);
  }
  printf("\n");
  return 0;
}
