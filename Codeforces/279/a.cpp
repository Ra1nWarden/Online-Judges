#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  vector<int> b;
  vector<int> c;
  for(int i= 1; i <= n;  i++) {
    int x;
    cin >> x;
    if(x == 1)
      a.push_back(i);
    else if(x == 2)
      b.push_back(i);
    else if(x == 3)
      c.push_back(i);
  }
  
  int result = min(a.size(), min(b.size(), c.size()));
  cout << result << endl;
  for(int j = 0; j < result; j++) {
    cout << a[j] << " " << b[j] << " " << c[j] << endl;
  }
  return 0;
}
