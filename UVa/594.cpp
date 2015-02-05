#include <iostream>
#include <bitset>

using namespace std;

int convert(bitset<32>& bits) {
  bitset<32> result;
  int shiftedbyte = 0;
  while(shiftedbyte < 4) {
    bitset<32> shifted = bits >> (shiftedbyte * 8) << 24 >> ( shiftedbyte * 8);
    result |= shifted;
    shiftedbyte++;
  }
  if (result.test(0)) {
    result = result.flip();
    return -(result.to_ulong() + 1);
  }
  else 
    return result.to_ulong();
}

int main() {
  int number;
  while(cin >> number) {
    bitset<32> bitsrep(number);
    cout << number << " converts to " << convert(bitsrep) << endl;
  }
  return 0;
}
