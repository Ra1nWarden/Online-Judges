#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  double g = 9.8;
  for(int i = 0; i < n; i++) {
    double h, v;
    cin >> h >> v;
    printf("%.2f\n", v/g*sqrt(v*v + 2*g*h));
  }
  return 0;
}
