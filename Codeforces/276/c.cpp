#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdio>

using namespace std;

bitset<64> calc(bitset<64> start, bitset<64> end) {
  bitset<64> result(0);
  int lead = 0;
  for(int i = 63; i >= 0; i--) {
    if(end.test(i) && !start.test(i)) {
      for(int j= i-1; j >= 0; j--)
	result.set(j);
      break;
  
    }
    else if(start.test(i), end.test(i)) {
      result.set(i);
      bitset<64> newstart = start;
      bitset<64> newend = end;
      newstart.reset(i);
      newend.reset(i);
      result |= calc(newstart, newend);
      break;
    }
  }
  return end.count() > result.count() ? end : result;
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    uint64_t start, end;
    cin >> start >> end;
    bitset<64> startbits(start);
    bitset<64> endbits(end);
    bitset<64> result = calc(startbits, endbits);
    // cout << startbits << endl;
    //cout << endbits << endl;
    //cout << result << endl;
    cout << result.to_ullong() << endl;
  }
  return 0;
}
