#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<long long, int> LLI;
typedef pair<int, int> II;
typedef pair<long long, II> Node;

const int maxn = 200000;
long long cnt[maxn+5];

int main() {
  int n;
  scanf("%d", &n);
  vector<LLI> v;
  for(int i = 0; i < n; i++) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    v.push_back(make_pair(a, 0));
    v.push_back(make_pair(b, 1));
  }
  sort(v.begin(), v.end());

  vector<Node> agg; 
  for(int i = 0; i < v.size(); i++) {
    int a = 0, b = 0;
    int j;
    for(j = i; j < v.size(); j++) {
      if(v[j].first != v[i].first)
	break;
      if(v[j].second == 0)
	a++;
      else
	b++;
    }
    agg.push_back(make_pair(v[i].first, make_pair(a, b)));
    i = j - 1;
  }

  memset(cnt, 0, sizeof cnt);
  int cur = 0;
  for(int i = 0; i < agg.size(); i++) {
    if(agg[i].second.first > 0 && agg[i].second.second > 0) {
      // add and subtract
      if(i)
	cnt[cur] += agg[i].first - agg[i-1].first - 1;
      cur += agg[i].second.first;
      cnt[cur]++;
      cur -= agg[i].second.second;
    } else if(agg[i].second.first > 0) {
      // add
      if(i)
	cnt[cur] += agg[i].first - agg[i-1].first - 1;
      cur += agg[i].second.first;
      cnt[cur]++;
    } else {
      // subtract
      if(i)
	cnt[cur] += agg[i].first - agg[i-1].first;
      cur -= agg[i].second.second;
    }
  }

  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%lld", cnt[i]);
  }
  printf("\n");
  
  return 0;
}
