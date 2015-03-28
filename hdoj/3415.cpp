#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXN 200005
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int arr[MAXN];

typedef pair<int, int> II;

II v[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    arr[0] = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
      arr[i] += arr[i-1];
    }
    for(int i = n +1; i <= n + k; i++)
      arr[i] = arr[n] + arr[i - n];
    int front = 0;
    int rear = 0;
    rear++;
    v[front].first = 0;
    v[front].second = 0;
    int index = 1;

    int ans = -2e9;
    int start = -1;
    int end = -1;
    
    for(int i = 1; i <= n; i++) {
      while(index - i < k) {
	int nextVal = arr[index];
	while(front < rear && v[rear - 1].first < nextVal)
	  rear--;
	v[rear].first = nextVal;
	v[rear].second = index;
	index++;
	rear++;
      }
      while(front < rear && v[front].second < i)
	front++;
      int maxVal = v[front].first - arr[i-1];
      if(maxVal > ans) {
	ans = maxVal;
	start = i;
	end = v[front].second;
      }
    }
    printf("%d %d %d\n", ans, start, end > n ? end - n : end);
  
  }
  return 0;
}
