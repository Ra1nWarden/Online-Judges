#include <iostream>

using namespace std;

string transform(string num, int inc) {
  string result = num;
  for(int i = 0; i < result.length(); i++) {
    result[i] = (result[i] - '0' + inc) % 10 + '0';
  }
  return result;
}

int main() {
  int l;
  cin >> l >> ws;
  string number;
  getline(cin, number);
  string minnum(number.length(), '9');
  for(int i = 0; i < l; i++) {
    char cur = number[i];
    int num = cur - '0';
    int incre = num == 0 ? 0 : 10 - num;
    string newstring = number.substr(i) + number.substr(0, i);
    minnum = min(transform(newstring, incre), minnum);
  }
  cout << minnum << endl;
  return 0;
}
