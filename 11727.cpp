#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    vector<int> triplets;
    int a, b, c;
    cin >> a >> b >> c;
    triplets.push_back(a);
    triplets.push_back(b);
    triplets.push_back(c);
    sort(triplets.begin(), triplets.end());
    cout << "Case " << i+1 << ": " << triplets[1] << endl;
  }
  return 0;
}
