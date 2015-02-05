#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 50005

using namespace std;

int n;
int tcase;

struct Node {
  int l, r, s;
  Node() {};
};

Node segTree[MAXN * 4];

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].s = 0;
  if(l == r) {
    //    segTree[i].s = v[l];
    return;
  }
  int mid = (l + r) / 2; 
  build(i*2, l, mid);
  build(i*2 + 1, mid+1, r);
  //segTree[i].s = segTree[i*2].s + segTree[i * 2 + 1].s;
}

void update(int i, int k, int x) {
  segTree[i].s += x;
  if(segTree[i].l == k && segTree[i].r == k) {
    //segTree[i].s += x;
    return;
  }
  int mid = (segTree[i].l + segTree[i].r) / 2;
  if(k <= mid) {
    update(i*2, k, x);
  } else {
    update(i*2+1, k, x);
  }
  // segTree[i].s = segTree[i*2].s + segTree[i*2+1].s;
}

int query(int i, int l, int r) {
  if(segTree[i].l == l && segTree[i].r == r)
    return segTree[i].s;
  if(segTree[i].l > r || segTree[i].r < l)
    return 0;
  int mid = (segTree[i].l+segTree[i].r) / 2;
  if(r <= mid)
    return query(i*2, l, r);
  else if (l > mid)
    return query(i*2+1, l, r);
  else {
    return query(i*2, l, mid) + query(i*2+1, mid+1, r);
  }
}


int main() {
  // int tc;
  // scanf("%d", &tc);
  // for(int et = 1; et <= tc; et++) {
  //   printf("Case %d:\n", et);
  //   scanf("%d", &n);
  //   build(1, 1, n);
  //   int val;
  //   for(int i = 1; i <= n; i++) {
  //     scanf("%d", &val);
  //     update(1, i, val);
  //   }
 
  //   string cmd;
  //   int x, y;
  //   while(true) {
  //     cin >> cmd >> x >> y;
  //     if(cmd == "Query") {
  // 	printf("%d\n", query(1, x, y));
  //     }
  //     else if(cmd == "Add") {
  // 	update(1, x, y);
  //     }
  //     else if(cmd == "Sub") {
  // 	update(1, x, -y);
  //     }
  //     else {
  // 	break;
  //     }
  //   }
  // }
  // return 0;
 char    str[20] ;  
    int     i, j ;  
    int     x, y ;  
  
    while (scanf ("%d", &tcase) != EOF)  
    {  
        for (j = 1 ; j <= tcase ; ++j)  
        {  
            scanf ("%d", &n) ;  
            build (1, 1, n) ;  
            for (i = 1 ; i <= n ; ++i)  
            {  
                scanf ("%d", &x) ;  
                // ?i x  
                update (1, i, x) ;  
            }  
            printf ("Case %d:\n", j) ;  
            while (scanf ("%s", str), *str != 'E')  
            {  
                scanf ("%d%d", &x, &y) ;  
                if (*str == 'Q')  
                    printf ("%d\n", query (1, x, y)) ;  
                else if (*str == 'A')  
                    update (1, x, y) ;  
                else if (*str == 'S')  
                    update (1, x, -y) ;  
            }  
        }  
    }  
    return 0 ;  
}
