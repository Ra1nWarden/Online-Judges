#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 1; et <= tc; et++) {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("Case %d: ", et);
    if(a <= 0 || b <= 0 || c <= 0) {
      printf("Invalid\n");
    } else if((a+b) > c && abs(a-b) < c && (a+c) > b && abs(a-c) < b && (b+c) > a && abs(b-c) < a) {
      if(a == b && b == c) {
	printf("Equilateral\n");
      } else if(a == b || b == c || a == c) {
	printf("Isosceles\n");
      } else {
	printf("Scalene\n");
      }
    } else {
      printf("Invalid\n");
    }
  }
  return 0;
}
