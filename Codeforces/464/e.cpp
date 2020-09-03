#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  vector<int> v;
  vector<long long> sum;
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int num;
      scanf("%d", &num);
      v.push_back(num);
      if(sum.empty()) {
	sum.push_back((long long) num);
      } else {
	sum.push_back(sum.back() + v.back());
      }
    } else {
      if(v.size() == 1) {
	printf("%.10lf\n", 0);
      } else {
	int l = 0, r = v.size() - 2;
	while(l != r) {
	  int m = ((l + r) >> 1) + 1;
	  double avg = (sum[m] + v.back()) * 1.0 / (m + 2);
	  if(v[m] > avg) {
	    r = m - 1;
	  } else {
	    l = m;
	  }
	}
	printf("%.10lf\n", v.back() - (sum[l] + v.back()) * 1.0 / (l + 2));
      }
    }
  }
  return 0;
}
