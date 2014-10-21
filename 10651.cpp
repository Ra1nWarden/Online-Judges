#include <bitset>
#include <iostream>
#include <cstring>

using namespace std;

int dp[1 << 13];

bool DEBUG = false;

ostream& operator<<(ostream& oss, const bitset<12>& bits) {
  for(int i= 0; i < 12; i++)
    oss << bits[i];
  return oss;
}

int f(int bitmask) {
  if(dp[bitmask] < 13)
    return dp[bitmask];
  int result = 12;
  bitset<12> bits(bitmask);
  bool jumped = false;
  for(int i= 0; i < 11; i++) {
    if(bits[i] && bits[i+1]) {
      if(i > 0 && !bits[i-1]) {
	jumped = true;
	bitset<12> newbits(bitmask);
	newbits[i] = 0;
	newbits[i+1] = 0;
	newbits[i-1] = 1;
	if(DEBUG)
	  cout << "jumping left from " << bits << " to " << newbits << endl;
	result = min(result, f(newbits.to_ulong()));
      }
      if(i+2 < 12 && !bits[i+2]) {
	jumped = true;
	bitset<12> newbits(bitmask);
	newbits[i] = 0;
	newbits[i+1] = 0;
	newbits[i+2] = 1;
	if(DEBUG)
	  cout << "jumping right from " << bits << " to " << newbits << endl;
	result = min(result, f(newbits.to_ulong()));
      }
    }
  }
  if(jumped)
    return dp[bitmask] = result;
  else {
    result = 0;
    for(int i = 0; i < 12; i++) {
      result += (bits[i] == 1 ? 1 : 0);
    }
    return dp[bitmask] = result;
  }
}

int main() {
  int cases;
  memset(dp, 13, sizeof dp);
  for(int i = 0; i < 13; i++) {
    dp[1 << i] = 1;
  }
  cin >> cases >> ws;
  while(cases--) {
    string line;
    getline(cin, line);
    bitset<12> next;
    for(int i= 0; i < 12; i++) {
      if(line[i] == 'o')
	next[i] = 1;
      else
	next[i] = 0;
    }
    cout << f(next.to_ulong()) << endl;
  }
  return 0;
}
