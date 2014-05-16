#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ostream& operator<<(ostream& oss, const vector<long>& vec) {
  for(long i = 0; i < vec.size(); i++)
    oss << vec[i] << " ";
  oss << endl;
  return oss;
}

long mergeCount(vector<long>& unsorted) {
  if(unsorted.size() <= 1)
    return 0;
  long half = unsorted.size() / 2;
  vector<long> first, second;
  for(long i = 0; i < unsorted.size(); i++) {
    if(i < half)
      first.push_back(unsorted[i]);
    else
      second.push_back(unsorted[i]);
  }
  long result = mergeCount(first) + mergeCount(second);
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  // cout << "first and second are sorted " << first << " and " << second << " result is " << result << endl;
  long runningOne = 0;
  long runningTwo = 0;
  for(long i = 0; i < unsorted.size(); i++) {
    if(runningOne == first.size() || runningTwo == second.size())
      break;
    if(first[runningOne] <= second[runningTwo]) {
      runningOne++;
    }
    else {
      result += (first.size() - runningOne);
      runningTwo++;
    }
  }
  // cout << "finished merging, result is now " << result << endl;
  return result;
}

int main() {
  while(true) {
    long counts;
    cin >> counts;
    if(counts == 0)
      break;
    vector<long> unsorted;
    for(long i = 0; i < counts; i++) {
      long each;
      cin >> each;
      unsorted.push_back(each);
    }
    cout << mergeCount(unsorted) << endl;
  }
  return 0;
}
