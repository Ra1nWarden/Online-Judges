#include <cstdio>
#include <deque>
#include <vector>
#include <string>

using namespace std;

deque<int> v;
int n;

bool sorted() {
  for(int i = 0; i < v.size() - 1; i++) {
    if(v[i] + 1 != v[i+1]) {
      if(v[i] == n && v[i+1] == 1)
	continue;
      return false;
    }
  }
  return true;
}

int main() {
  while(scanf("%d", &n) != EOF && n) {
    v.clear();
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      v.push_back(num);
    }
    vector<int> ans;
    while(!sorted()) {
      int a = v[0];
      int b = v[1];
      if(a > b && !(a == n && b == 1)) {
	swap(v[0], v[1]);
	ans.push_back(1);
      } else {
	v.push_front(v.back());
	v.pop_back();
	ans.push_back(2);
      }
    }
    int start = 0;
    while(v[start] != 1) {
      ans.push_back(2);
      start = (start + n - 1) % n;
    }
    for(int i = ans.size() - 1; i > -1; i--) {
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
