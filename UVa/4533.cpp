#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

// in increasing order,
map<vector<long long>, set<long long> > myMap;

void mergeSets(set<long long>& a, set<long long>& b) {
  for(set<long long>::iterator itr = b.begin(); itr != b.end(); ++itr)
    a.insert(*itr);
}

ostream& operator<<(ostream& os, vector<long long>& myVec) {
  for(int i =0; i < myVec.size(); i++)
    cout << myVec[i] << " ";
  return os;
}

ostream& operator<<(ostream& os, set<long long>& mySet){
  for(set<long long>::iterator itr = mySet.begin(); itr != mySet.end(); ++itr)
    cout << *itr << " ";
  return os;
}

set<long long> getResult(vector<long long>& numbers) {
  sort(numbers.begin(), numbers.end());
  if(myMap.count(numbers) == 1)
    return myMap[numbers]; 
  if(numbers.size() == 2) {
    set<long long> result;
    long long small = numbers[0];
    long long large = numbers[1];
    // add
    result.insert(small+large);
    // sub
    result.insert(small-large);
    result.insert(large-small);
    // mult
    result.insert(small*large);
    // div
    if(small != 0) {
      if(large % small == 0)
	result.insert(large/small);
    }
    myMap[numbers] = result;
    return result;
  }
  else {
    set<long long> result;
    // always start with 2 numbers
    for(int i = 0; i < numbers.size() - 1; i++) {
      for(int j = i+1; j < numbers.size(); j++) {
	long long a = numbers[i];
	long long b = numbers[j];
	vector<long long> newnumberset;
	newnumberset.push_back(a);
	newnumberset.push_back(b);
	set<long long> subresult = getResult(newnumberset);
	vector<long long> finalset;
	for(int k = 0; k < numbers.size(); k++) {
	  if(k == i || k == j)
	    continue;
	  finalset.push_back(numbers[k]);
	}
	for(set<long long>::iterator itr = subresult.begin(); itr != subresult.end(); itr++) {
	  vector<long long> threenumbers = finalset;
	  threenumbers.push_back(*itr);
	  set<long long> thisresult = getResult(threenumbers);
	  mergeSets(result, thisresult);
	}
      }
    }
    myMap[numbers] = result;
    return result;
  }
}

int main() {
  int cases = 1;
  while(true) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == 0 && b == 0 && c == 0 && d == 0)
      break;
    vector<long long> numbers;
    numbers.push_back(a);
    numbers.push_back(b);
    numbers.push_back(c);
    numbers.push_back(d);
    set<long long> result = getResult(numbers);
    long longest = 1;
    set<long long>::iterator itr = result.begin();
    long long start = *itr;
    long long end = *itr;
    itr++;
    long runninglength = 1;
    long long runningstart = start;
    long long runningend = end;
    for( ; itr != result.end(); ++itr) {
      if((*itr) - runningend > 1) {
	runningstart = *itr;
	runninglength = 1;
      }
      else
	runninglength++; 
      runningend = *itr;
      if(runninglength >= longest) {
	longest = runninglength;
	start = runningstart;
	end = runningend;
      }
    }
    if(cases != 1)
      cout << "\n";
    cout << "Case " << cases << ": " << start << " to " << end;
    cases++;
  }
  return 0;
}
