#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < n - 1; i++) {
    int minpos = i;
    for(int j = i+1; j < n; j++) {
      if(v[j] < v[minpos]) {
	minpos = j;
      }
    }
    if(minpos != i) {
      for(int j = minpos - 1; j >= i; j--) {
	swap(v[j], v[j+1]);
	printf("%d %d\n", j+1, j+2);
      }
    }
  }
  return 0;
}
