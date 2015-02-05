#include <iostream>
#include <cmath>
#define EPS 2e-9
#define PI 3.141592653

using namespace std;

int main() {
  double a, b, v, angle, s;
  while(cin >> a >> b >> v >> angle >> s && (a || b || v || angle || s)) {
    double hyp = pow(v, 2) / (2 * v / s);
    double horizontal = hyp * cos(angle * PI / 180);
    double vertical = hyp * sin(angle * PI / 180);
    int hr = 0;
    int vr = 0;
    if(horizontal + EPS >= a / 2) {
      vr = 1;
      vr += (horizontal - a / 2) / a;
    }
    if(vertical + EPS >= b / 2) {
      hr = 1;
      hr += (vertical - b / 2) / b;
    }
    cout << vr << " " << hr << endl;
  }

}
