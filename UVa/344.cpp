#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int ii[101];
  int vi[101];
  int xi[101];
  int li[101];
  int ci[101];
  ii[0] = 0; vi[0] = 0; xi[0]= 0; li[0] = 0; ci[0] = 0;
  for(int n= 1; n <= 100; n++) {
    int ncopy = n;
    int i = 0, v = 0, x = 0, l = 0, c = 0;
    c = ncopy / 100;
    ncopy %= 100;
    int ten = ncopy / 10;
    ncopy %= 10;
    if(ten > 3 && ten < 9) {
      l = 1;
      x = abs(ten - 5);
    } else if(ten == 9) {
      x = 1;
      c += 1;
    } else
      x = ten;
    int one = ncopy;
    if(one > 3 && one < 9) {
      v = 1;
      i = abs(5 - one);
    } else if(one == 9) {
      i = 1;
      x += 1;
    } else {
      i = one;
    }
    
    ii[n] = ii[n-1] + i;
    vi[n] = vi[n-1] + v;
    xi[n] = xi[n-1] + x;
    li[n] = li[n-1] + l;
    ci[n] = ci[n-1] + c;
  }

  // for(int i = 1; i <= 20; i++) {
  //   cout << i << " i: " << ii[i] << " v: " << vi[i] << " x: " << xi[i] << " l: " << li[i] << " c: " << ci[i] << endl;
  // }

  int n;
  while(cin >> n && n) {
    printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, ii[n], vi[n], xi[n], li[n], ci[n]);
  }
    return 0;
}
