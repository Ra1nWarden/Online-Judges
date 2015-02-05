#include <iostream>

using namespace std;

int main() {
  int n, m, c;
  while(cin >> n >> m >> c && (n || m || c)) {
    bool firstBlack = (c + (n % 2 + m % 2)) % 2;
    int hor = m > 8 ? (m - 8 - 1) / 2 + 1 : 0; // assume its white
    int ver = n - 8 + 1;
    //cout << "firstBlack? " << firstBlack << endl;
    //cout << hor << ", " << ver << endl;
    int result = hor * ver;
    if(m % 2 == 0)
      result += ver / 2;
    if(firstBlack && ver % 2 == 1 && c == 1) {
      result += 1;
    }
    cout << result << endl;
  }
  return 0;
}
