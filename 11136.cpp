#include <iostream>
#include <set>

using namespace std;

int main() {
  while(true) {
    long count;
    cin >> count;
    if(count == 0)
      break;
    multiset<long> multSetOne;
    long result = 0;
    for(long i = 0; i < count; i++) {
      long subCount;
      cin >> subCount;
      for(long j = 0; j < subCount; j++) {
	long reciept;
	cin >> reciept;
	multSetOne.insert(reciept);
      }
      long small = *multSetOne.begin();
      long large = *(--multSetOne.end());
      result += (large - small);
      multSetOne.erase(multSetOne.begin());
      multSetOne.erase(--multSetOne.end());
    }
    cout << result << endl;
  }
  return 0;
}
