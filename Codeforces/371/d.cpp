#include <cstdio>
#include <map>

using namespace std;

typedef pair<pair<long long, long long>, pair<long long, long long> > Query;

long long n;
map<Query, int> h;

int test(long long r1, long long c1, long long r2, long long c2) {
  Query k = make_pair(make_pair(r1, c1), make_pair(r2, c2));
  if(h.count(k))
    return h[k];
  printf("? %I64d %I64d %I64d %I64d\n", r1, c1, r2, c2);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  h[k] = ans;
  return ans;
}

long long bsearch(long long r1, long long c1, long long r2, long long c2, long long t, bool pos) {
  long long left = 1;
  long long right = n;
  while(left != right) {
    if(pos) {
      long long mid = (left + right) >> 1;
      if(test(r1 == 0 ? mid : r1, c1 == 0 ? mid : c1, r2 == 0 ? mid : r2, c2 == 0 ? mid : c2) >= t) {
	right = mid;
      } else {
	left = mid + 1;
      }
    } else {
      long long mid = ((left + right) >> 1) + 1;
      if(test(r1 == 0 ? mid : r1, c1 == 0 ? mid : c1, r2 == 0 ? mid : r2, c2 == 0 ? mid : c2) >= t) {
	left = mid;
      } else {
	right = mid - 1;
      }
    }
  }
  return left;
}

int main() {
  scanf("%I64d", &n);
  // vertical -> finding right: btm left is (1, 1), top right is (n, x)
  long long r2 = bsearch(1, 1, n, 0, 2, true);
  long long r1 = bsearch(1, 1, n, 0, 1, true);

  // vertical -> finding left: btm left is (1, x), top right is (n, n)
 
  long long l2 = bsearch(1, 0, n, n, 2, false);
  long long l1 = bsearch(1, 0, n, n, 1, false);

  //printf("r2=%I64d r1=%I64d l2=%I64d l1=%I64d\n", r2, r1, l2, l1);

  long long v11, v12, v21, v22;
  if(r1 >= l1 && test(1, l1, n, r1) > 0) {
    v11 = l1;
    v12 = r1;
    v21 = l2;
    v22 = r2;
  } else {
    v11 = l1;
    v12 = r2;
    v21 = l2;
    v22 = r1;
  }

  //printf("v11=%I64d v12=%I64d v21=%I64d v22=%I64d\n", v11, v12, v21, v22);
  
  // horizontal -> finding top: btm left is (1, 1), top right is (x, n)
  long long t2 = bsearch(1, 1, 0, n, 2, true);
  long long t1 = bsearch(1, 1, 0, n, 1, true);

  // horizontal -> finding btm: btm left is (x, 1), top right is (n, n)
  long long b2 = bsearch(0, 1, n, n, 2, false);
  long long b1 = bsearch(0, 1, n, n, 1, false);

  //printf("t2=%I64d t1=%I64d b2=%I64d b1=%I64d\n", t2, t1, b2, b1);

  long long h11, h12, h21, h22;
  if(t1 >= b1 && test(b1, 1, t1, n) > 0) {
    h11 = b1;
    h12 = t1;
    h21 = b2;
    h22 = t2;
  } else {
    h11 = b1;
    h12 = t2;
    h21 = b2;
    h22 = t1;
  }

  //printf("h11=%I64d h12=%I64d h21=%I64d h22=%I64d\n", h11, h12, h21, h22);

  if(test(h11, v11, h12, v12) == 1) {
    printf("! %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n", h11, v11, h12, v12, h21, v21, h22, v22);
  } else {
    printf("! %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n", h11, v21, h12, v22, h21, v11, h22, v12);
  }
  return 0;
}
