#include <cstdio>
#include <vector>
#define MAXN 100005

using namespace std;

vector<int> odd;
vector<int> even;

int main() {
  int n, k, p;
  scanf("%d %d %d", &n, &k, &p);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    bool oddf = num % 2;
    if(oddf)
      odd.push_back(num);
    else
      even.push_back(num);
  }
  int oddn = k - p;
  int oddcnt = odd.size();
  int evencnt = even.size();
  if(evencnt < p) {
    oddcnt -= 2 * (p - evencnt);
  }
  if(oddcnt < oddn || (oddcnt - oddn) % 2 == 1) {
    printf("NO\n");
    return 0;
  }
  vector<vector<int> > ans;
  int ei = 0, oi = 0;
  for(int i =0 ; i < p; i++) {
    vector<int> each;
    if(i == p - 1) {
      if(ei < even.size()) {
	while(ei < even.size())
	  each.push_back(even[ei++]);
      } else {
	each.push_back(odd[oi++]);
	each.push_back(odd[oi++]);
      }
      if(oddn == 0) {
	while(oi < odd.size())
	  each.push_back(odd[oi++]);
      }
    } else {
      if(ei < even.size()) {
	each.push_back(even[ei++]);
      } else {
	each.push_back(odd[oi++]);
	each.push_back(odd[oi++]);
      }
    }
    ans.push_back(each);
  }
  for(int i = 0; i < oddn; i++) {
    vector<int> each;
    if(i == oddn - 1) {
      while(oi < odd.size())
	each.push_back(odd[oi++]);
      if(p == 0) {
	while(ei < even.size())
	  each.push_back(even[ei++]);
      }
    } else {
      each.push_back(odd[oi++]);
    }
    ans.push_back(each);
  }
  printf("YES\n");
  for(int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i].size());
    for(int j = 0; j < ans[i].size(); j++) {
      printf(" %d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
