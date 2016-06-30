#include <cstdio>
#include <map>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  map<int, int> cnt;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(cnt.count(num)) {
      cnt[num] = cnt[num] + 1;
    } else {
      cnt[num] = 1;
    }
  }
  int prev = 0;
  int sum = 0;
  for(map<int, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++) {
    int s = itr->first;
    int v = itr->second;
    prev += v;
    prev = min(prev, s);
  }
  printf("%d\n", prev + 1);
  return 0;
}
