#include <iostream>
#include <vector>

using namespace std;

bool DEBUG = false;

bool groupOk(vector<long long>& numbers, int start, int group, long long sum) {
  if (DEBUG) {
    cout << "begin groupOK" << endl;
    cout << "group count " << group << " sum is " << sum << endl;
    for (int i= 0; i < numbers.size(); i++)
      cout << numbers[i] << " ";
    cout << endl;
  }
  int n = 1;
  int index = start;
  long long rsum = 0;
  while (index < numbers.size()) {
    if (numbers[index] > sum)
      return false;
    if (rsum + numbers[index] > sum) {
      if (DEBUG) {
	cout << "index is " << index << " number is " << numbers[index] << " rsum is " << rsum << endl; 
      }
      n++;
      index--;
      rsum = 0;
    } else {
      rsum += numbers[index];
    }
    index++;
  }
  if (DEBUG) cout << "end groupOK" << endl;
  return n <= group;
}

long long findOpt(vector<long long>& numbers, int group, long long start, long long end) {
  if (start == end)
    return start;
  long long mid = (start + end) / 2;
  if (groupOk(numbers, 0, group, mid)) {
    return findOpt(numbers, group, start, mid);
  } else {
    if (DEBUG) {
      cout << "else calling " << mid << " " << end << endl;
    }
    return findOpt(numbers, group, mid+1, end);
  }
}

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int count, group;
    cin >> count >> group;
    vector<long long> numbers;
    long long sum = 0;
    for (int j = 0; j < count; j++) {
      long long number;
      cin >> number;
      numbers.push_back(number);
      sum += number;
    }
    long long lowerbound = sum / group;
    long long optimal = findOpt(numbers, group, lowerbound, sum);
    int groupsLeft = group - 1;
    for (int j = 0; j < numbers.size(); j++) {
      if (j != numbers.size() - 1) {
	if (groupOk(numbers, j+1, groupsLeft, optimal)) {
	  cout << numbers[j] << " / ";
	  groupsLeft--;
	} else {
	  cout << numbers[j] << " ";
	}
	
      } else {
	cout << numbers[j] << endl;
      }
    }
  }
  return 0;
}
