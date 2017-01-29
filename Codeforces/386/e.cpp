#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 200000;
struct Node {
  int idx, val;
  Node() {}
  Node(int i, int v) {
    idx = i;
    val = v;
  }
  bool operator<(const Node& rhs) const {
    return val < rhs.val;
  }
};
Node odd[maxn+5];
Node even[maxn+5];
int n, m, oi, ei;
int v[2*maxn+5];
set<int> seen;

int unique_sort(Node* start, int len) {
  int si = 0;
  int idx = 0;
  int prev = -1;
  while(idx < len) {
    if(start[idx].val != prev) {
      prev = start[idx].val;
      swap(start[idx].val, start[si].val);
      swap(start[idx].idx, start[si].idx);
      si++;
    }
    idx++;
  }
  return si;
}

int main() {
  scanf("%d%d", &n, &m);
  oi = ei = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    seen.insert(v[i]);
    if(v[i] & 1) {
      odd[oi++] = Node(i, v[i]);
    } else {
      even[ei++] = Node(i, v[i]);
    }
  }
  sort(odd, odd + oi);
  sort(even, even + ei);
  int uoi = unique_sort(odd, oi);
  int uei = unique_sort(even, ei);
  int num = 1;
  int change = 0;
  while(uoi < n / 2) {
    while(seen.count(num)) {
      num += 2;
    }
    if(num > m) {
      printf("-1\n");
      return 0;
    }
    seen.insert(num);
    if(uoi < oi) {
      odd[uoi].val = num;
      v[odd[uoi].idx] = num;
    } else {
      even[ei-1].val = num;
      v[even[ei-1].idx] = num;
      ei--;
    }
    change++;
    uoi++;
  }
  num = 2;
  while(uei < n / 2) {
    while(seen.count(num)) {
      num += 2;
    }
    if(num > m) {
      printf("-1\n");
      return 0;
    }
    seen.insert(num);
    if(uei < ei) {
      even[uei].val = num;
      v[even[uei].idx] = num;
    } else {
      odd[oi-1].val = num;
      v[odd[oi-1].idx] = num;
      oi--;
    }
    change++;
    uei++;
  }
  printf("%d\n", change);
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
