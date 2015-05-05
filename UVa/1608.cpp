#include <cstdio>
#include <cstring>
#include <map>
//#define TABLESIZE 300007
#define MAXN 200005

using namespace std;

// int head[TABLESIZE], next[TABLESIZE];
// int values[MAXN];
// int idx;
// int keys[MAXN];

// int hash(int x) {
//   return x % TABLESIZE;
// }

// bool insert(int k, int v, int& old) {
//   int h = hash(k);
//   int u = head[h];
//   while(u) {
//     if(keys[u] == k) {
//       old = values[u];
//       values[u] = v;
//       return true;
//     }
//     u = next[u];
//   }
//   next[idx] = head[h];
//   head[h] = idx;
//   keys[idx] = k;
//   values[idx++] = v;
//   return false;
// }

// void init_table() {
//   idx = 1;
//   memset(head, 0, sizeof head);
//   memset(next, 0, sizeof next);
// }

int v[MAXN];
int n;
int previ[MAXN];
int nexti[MAXN];
map<int, int> m;

bool unique(int i, int start, int end) {
  return previ[i] < start && nexti[i] > end;
}

bool check(int start, int end) {
  //printf("check %d %d\n", start, end);
  if(start >= end)
    return true;
  for(int d = 0; start + d <= end - d; d++) {
    if(unique(start + d, start, end))
      return check(start, start + d - 1) && check(start + d + 1, end);
    if(start+d == end - d)
      break;
    if(unique(end - d, start, end))
      return check(start, end - d - 1) && check(end - d + 1, end);
  }
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    //init_table();
    //memset(previ, -1, sizeof previ);
    //memset(nexti, -1, sizeof nexti);
    m.clear();
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      if(m.count(v[i]))
	previ[i] = m[v[i]];
      else
      	previ[i] = -1;
      m[v[i]] = i;
      // int ii;
      // if(insert(v[i], i, ii)) {
      // 	previ[i] = ii;
      // } else {
      // 	previ[i] = -1;
      // }
    }
    //init_table();
    m.clear();
    for(int i = n - 1; i > -1; i--) {
      if(m.count(v[i]))
      	nexti[i] = m[v[i]];
      else
      	nexti[i] = n;
      m[v[i]] = i;
      // int ii;
      // if(insert(v[i], i, ii)) {
      // 	nexti[i] = ii;	
      // } else {
      // 	nexti[i] = n;
      // }
    }
    if(check(0, n-1))
      printf("non-boring\n");
    else
      printf("boring\n"); 
  }
  return 0;
}
