#include <iostream>

using namespace std;

int solve(unsigned long long num) {
  if(num < 5) {
    if(num % 2)
      return 0;
    else
      return num / 2;
  }
  unsigned long long lower;
  int i;
  for(; i <= 63; i++) {
    unsigned long long bound = 1ULL << i;
    if(bound < num) {
      lower = bound;
    } else {
      break;
    }
  }
  unsigned long long left = num - lower;
  int cnt = 1;
  for(int ii = i - 2; ii > 1; ii--, cnt++) {
    unsigned long long length = ii > 1 ? 1ULL << (ii - 1) : 1;
    unsigned long long total = length * cnt;
    if(left <= total) {
      unsigned long long offset = left % length == 0 ? length : left % length;
      offset += (1ULL << (ii - 1));
      return solve(offset);
    } else {
      left -= total;
    }
  }
  
  if(left <= cnt) {
    return 1;
  } else if(left <= cnt + cnt + 1) {
    return 0;
  } else {
    return i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  unsigned long long num;
  while(cin >> num && num) {
    cout << solve(num) << endl;
  }
  return 0;
}
