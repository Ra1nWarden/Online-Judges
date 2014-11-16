#include <iostream>
#include <cstring>

using namespace std;

int dp[25001];
string words[25001];
int result = 1;

int search(string w, int start, int end) {
  if(end < start)
    return -1;
  if(start == end) {
    return words[start] == w ? start : -1;
  }
  int mid = (start + end) / 2;
  if(words[mid] == w)
    return mid;
  else if (words[mid] < w)
    return search(w, mid + 1, end);
  else
    return search(w, start, mid - 1);
}

int main() {
  string line;
  int index = 0;
  while(cin >> line)
    words[index++] = line;
  for(int i= 0; i < index; i++) {
    dp[i] = 1;
    string orig = words[i];
    //cout << "orig word is " << orig << endl;

    for(int j = 0; j < orig.length(); j++) {
      string changed;
      int found;

      // delete
      if(j == orig.length() - 1 || orig[j+1] <= orig[j]) {
	changed = orig.substr(0, j);
	if(j + 1 < orig.length())
	  changed += orig.substr(j+1);
	//cout << "delete: word is " << changed << endl;
	found = search(changed, 0, i-1);
	if(found != -1)
	  dp[i] = max(dp[i], dp[found] + 1);
      }

      // add
      for(char c = 'a'; c <= 'z'; c++) {
	if(c <= orig[j]) {
	  changed = orig.substr(0, j) + c;
	  if(j < orig.length())
	    changed += orig.substr(j);
	  //cout << "add: word is " << changed << endl;
	  found = search(changed, 0, i-1);
	  if(found != -1)
	    dp[i] = max(dp[i], dp[found] + 1);
	}
	
	// change
	if(c >= orig[j])
	  continue;
	changed = orig;
	changed[j] = c;
	//cout << "change: word is " << changed << endl;
	found = search(changed, 0, i-1);
	if(found != -1)
	  dp[i] = max(dp[i], dp[found] + 1);
      }
    }

    result = max(result, dp[i]);
    //cout << "just updated result with length " << result << " and the word is " << words[i] << endl;
  }
  cout << result << endl;
  return 0;
}
