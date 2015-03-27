#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for(int i= 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  int m;
  cin >> m;
  vector<int> b;
  for(int i= 0; i < m; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int scorea = 2 * a.size();
  int scoreb = 2 * b.size();
  int acount = 0;
  int maxdiff = 0;
  int acountr = 0;
  int bcountr = 0;
  for(int i = a.size() - 1; i >= 0; i--)  {
    int thresh = a[i];
    acount++;
    int bcount = b.end() - lower_bound(b.begin(), b.end(), thresh);
    if(acount - bcount >= maxdiff) {
      maxdiff = acount - bcount;
      acountr = acount;
      bcountr = bcount;
    }
  }
  cout << scorea + acountr << ":" << scoreb + bcountr << endl;
  return 0;
}
