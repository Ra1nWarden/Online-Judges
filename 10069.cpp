#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    string line, word;
    cin >> line >> word;
    vector<long long> checks(line.length());
    long long result = 0;
    for(int j = 0; j< checks.size(); j++)
      checks[j] = 0;
    for(int j = 0; j < word.length(); j++) {
      char currentchar = word[j];
      if(j == 0) {
	for(int k = 0; k < line.length(); k++) {
	  if(line[k] == currentchar)
	    checks[k]++;
	} 
	continue;
      }
      else if (j < word.length() - 1){
	long long runningsum = 0;
	char previous = word[j-1];
	for(int k = 0; k < line.length(); k++) {
	  long long temp;
	  if(line[k] == previous) {
	    if(previous == currentchar)
	      temp = runningsum;
	    runningsum += checks[k];
	  }
	  if(line[k] == currentchar) {
	    if(previous == currentchar)
	      checks[k] = temp;
	    else
	      checks[k] = runningsum;
	  }
	 
	}
      }
      else {
	long long runningsum = 0;
	char previous = word[j-1];
	for(int k = 0; k < line.length(); k++) {
	  if(line[k] == currentchar) {
	    checks[k] = runningsum;
	    result += runningsum;
	  }
	  if(line[k] == previous)
	    runningsum += checks[k];
	}
      }
    }
    cout << result << endl;
  }
  return 0;
}
