#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<string> v;
int n;

bool solve(vector<int> result) {
  //cout << "recursion on length " << result.size() <<  endl;
  //cout << "result array: " << endl;
  // for(int i= 0; i < result.size(); i++) {
  //   cout << result[i] << " ";
  // }
  // cout << endl;
  if(result.size() == n) {
    cout << "YES" << endl;
    for(int i= 0; i < result.size(); i++) {
      cout << result[i] << endl;
    }
    return true;
  }
  int last = -1;
  if(!result.empty())
    last = result.back();
  string next = v[result.size()];
  int counter = 0;
  for(int i= 0; i < next.length(); i++) {
    if(next[i] == '?')
      counter++;
  }
  if(counter == 0) {
    if(atoi(next.c_str()) <= last)
      return false;
    vector<int> newresult = result;
    newresult.push_back(atoi(next.c_str()));
    return solve(newresult);
  } else {
    int cap = pow(10, counter);
    for(int i= 0; i < cap; i++) {
      stringstream ss;
      ss << i;
      string fill = ss.str();
      while(fill.length() != counter)
	fill = "0" + fill;
      string newnumber = next;
      int insertIndex = 0;
      for(int j = 0; j < newnumber.length(); j++) {
	if(newnumber[j] == '?')
	  newnumber[j] = fill[insertIndex++];
      }
      if(newnumber[0] == '0')
	continue;
      else {
	int nextnum = atoi(newnumber.c_str());
	//cout << "next num is " << nextnum << endl;
	if(nextnum <= last)
	  continue;
	vector<int> newresult = result;
	newresult.push_back(nextnum);
	if(solve(newresult))
	  return true;
      }
    }
    return false;
  }
}

int main() {
  cin >> n >> ws;
  string line;
  for(int i= 0; i < n; i++) {
    getline(cin, line);
    v.push_back(line);
  }
  vector<int> result;
  if(!solve(result)) {
    cout << "NO" << endl;
  }
  return 0;
}
