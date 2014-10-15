#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
  vector<int> sequence;
  int caseNo = 1;
  int number;
  while(true) {
    cin >> number;
    if(number == -1 && sequence.empty()) {
      break;
    } else if(number == -1) {
      int length = sequence.size();
      vector<int> lcs(length, 1);
      int result = 1;
      for(int i= 1; i < sequence.size(); i++) {
	for(int j= 0; j < i; j++) {
	  if(sequence[i] < sequence[j]) {
	    lcs[i] = max(lcs[i], 1+lcs[j]);
	    if(lcs[i] > result)
	      result = lcs[i];
	  }
	}
      }
      if(caseNo > 1)
	cout << endl;
      printf("Test #%d:\n", caseNo++);
      printf("  maximum possible interceptions: %d\n", result);
      sequence.clear();
    } else {
      sequence.push_back(number);
    }
  }
  return 0;
}
