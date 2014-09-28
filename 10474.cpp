#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int count, query;
  int caseNo = 1;
  while(cin >> count >> query && (count || query)) {
    vector<int> q;
    for (int i = 0 ;i < count; i++) {
      int number;
      cin >> number;
      q.push_back(number);
    }
    sort(q.begin(), q.end());
    printf("CASE# %d:\n", caseNo);
    int guess;
    for (int i = 0; i < query; i++) {
      cin >> guess;
      vector<int>::iterator position = find(q.begin(), q.end(), guess);
      if (position == q.end()) {
	printf("%d not found\n", guess);
      } else {
	printf("%d found at %d\n", guess, (int) (position - q.begin()) + 1);
      }
    }
    caseNo++;
  }
  return 0;
}
