#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

bool DEBUG = false;

int main() {
  int x, y;
  int caseNo = 1;
  while(cin >> x >> y) {
    vector<int> numbers;
    map<int, bool> mapped;
    map<int, int> paired;
    int sum = 0;
    for (int i = 0; i < y; i++) {
      int number;
      cin >> number;
      sum += number;
      if(DEBUG)
	cout << "read in number is " << number << endl;
      numbers.push_back(number);
      mapped[number] = false;
    }
    if (DEBUG)
      cout << "numbers size is  "<< numbers.size() << endl;
    while(numbers.size() < x * 2) {
      numbers.push_back(0);
    }
    vector<int> sorted(numbers);
    sort(sorted.begin(), sorted.end());
    if(DEBUG) {
      cout << "sorted size is " << sorted.size() << endl;
      for(int i = 0; i < sorted.size(); i++) {
	cout << sorted[i] << ", ";
      }
      cout << endl;
    }
    for (int i = 0; i < x; i++) {
      int a = sorted[i];
      int b = sorted[sorted.size() - i - 1];
      if(DEBUG)
	cout << "a is " << a << " b is " << b << endl;
      paired[a] = b;
      paired[b] = a;
    }
    double average = ((double) sum) / x;
    double unbalance = 0.0;
    int printIndex = 0;
    cout << "Set #" << caseNo << endl;
    caseNo++;
    for (int i = 0; i < y; i++) {
      int nextNumber = numbers[i];
      if (!mapped[nextNumber]) {
	if (paired[nextNumber] != 0) {
	  printf(" %d: %d %d\n", printIndex++, nextNumber, paired[nextNumber]);
	  mapped[nextNumber] = true;
	  mapped[paired[nextNumber]] = true;
	  unbalance += abs(nextNumber + paired[nextNumber] - average);
	} 
	else {
	  printf(" %d: %d\n", printIndex++, nextNumber);
	  mapped[nextNumber] = true;
	  unbalance += abs(nextNumber - average);
	}
      }
    }
    while(printIndex < x) {
      printf(" %d:\n", printIndex++);
      unbalance += average;
    }
    printf("IMBALANCE = %.5f\n\n", unbalance);
  }
  return 0;
}
