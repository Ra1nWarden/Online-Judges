#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool _cmp(const string& a, const string& b) {
  return a + b > b + a;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n && n) {
    vector<string> numbers;
    string line;
    getline(cin, line);
    getline(cin, line);
    stringstream ss(line);
    string number;
    while(getline(ss, number, ' ')) {
      numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end(), _cmp);
    stringstream ans;
    for(int i = 0; i < numbers.size(); i++)
      ans << numbers[i];
    cout << ans.str() << endl;
  }
  return 0;
}
