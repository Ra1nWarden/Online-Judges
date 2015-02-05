#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check(vector<int>& seq) {
  int length = seq.size();
  stack<int> a, station;
  for(int i = length; i >= 1; i--)
    a.push(i);
  for(int i = 0; i < seq.size(); i++) {
    int current = seq[i];
    if (a.empty()) {
      if (station.top() != current)
	return false;
      else
	station.pop();
    }
    else {
      if (a.top() == current)
	a.pop();
      else if (station.empty()) {
	int popped = a.top();
	a.pop();
	station.push(popped);
	i--;
      }
      else if (station.top() == current)
	station.pop();
      else {
	int popped = a.top();
	a.pop();
	station.push(popped);
	i--;
      }
    }
  }
  return true;
}

int main() {
  int n;
  while(cin >> n) {
    if (n == 0)
      break;
    while(true) {
      bool loop = true;
      vector<int> seq;
      for(int i = 0; i < n; i++) {
	int number;
	if (i == 0) {
	  cin >> number;
	  if (number == 0) {
	    loop = false;
	    break;
	  }
	  else
	    seq.push_back(number);
	}
	else {
	  cin >> number;
	  seq.push_back(number);
	}
      }
      if (!loop)
	break;
      bool result = check(seq);
      if(result)
	cout << "Yes" << endl;
      else
	cout << "No" << endl;
    }
    cout << endl;
  }
  return 0;
}
