#include <iostream>
#include <bitset>

using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    bitset<32> bits(x);
    int length = 0;
    while(x > 0) {
      x = x >> 1;
      length++;
    }
    bitset<32> result;
    for(int j = 0; j < 32; j++) {
      if(j < length)
	result[j] = bits[length - j - 1];
      else
	result[j] = 0;
    }
    cout << result.to_ulong() << endl;
  }
  return 0;
}
